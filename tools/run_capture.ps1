# Starts JFGRecompiled (portable test folder, --start-game), captures its console output and takes
# screenshots of the game window (tools\shot_window.ps1, works while covered) at the given seconds, then stops it.
# Usage: powershell -ExecutionPolicy Bypass -File tools\run_capture.ps1 -Seconds 60 -Shots "20,40,60" `
#            [-ExtraArgs "--test-start-button"] [-Env "JFG_TRACE_AUDIO=1;JFG_TRACE_INPUT=1"]
# -ScriptTime: shot times (and -Seconds) count from the first pad poll, i.e. the JFG_INPUT_SCRIPT time base
#   (detected via the "[JFG] Scripted input:" line in jfg_trace.log of the run folder), not from the launch.
#
# Run validity (see RECOMP.md, "process investigation"): a run starts only when no JFGRecompiled.exe is running,
# binds to the PID of the game process it started (parent = its cmd.exe), takes screenshots of that PID only,
# samples the instance count during the run, and stops only that PID. Output ends with "RUN_PID=<pid>" and
# "RUN_VALID=1" or "RUN_VALID=0 (<reason>)". Exit code: 0 valid, 3 refused (instance running), 4 no game process, 5 invalid.
# -WindowSize "W,H": resize the game window (client area of the bound PID) right after launch, physical pixels, e.g. "1890,810" for 21:9.
param([int]$Seconds = 60, [string]$Shots = "20,40,60", [string]$ExtraArgs = "", [string]$Env = "", [switch]$NoConsole, [switch]$ScriptTime, [string]$WindowSize = "")
foreach ($kv in ($Env -split ";" | Where-Object { $_ })) { $k, $v = $kv -split "=", 2; Set-Item "env:$k" $v }
$root = Split-Path -Parent $PSScriptRoot
$run = Join-Path $root "build-cmake\run-jfg"
$out = Join-Path $root "runlogs"
New-Item -ItemType Directory -Force $out | Out-Null
$stamp = Get-Date -Format "MMdd_HHmmssfff"
$log = Join-Path $out "run_$stamp.log"
$exe = Join-Path $root "build-cmake\JFGRecompiled.exe"
$winshot = Join-Path $PSScriptRoot "shot_window.ps1"
$consoleArg = if ($NoConsole) { "" } else { "--show-console" }

function Get-GameInstances { @(Get-CimInstance Win32_Process -Filter "Name='JFGRecompiled.exe'" -ErrorAction SilentlyContinue) }

# 1. Refuse to start next to another instance: both would write the same run folder (trace, saves, mods.json).
$existing = @(Get-GameInstances)   # @() keeps a single result an array (PowerShell unrolls one object otherwise)
if ($existing.Count -gt 0) {
    "REFUSED: $($existing.Count) JFGRecompiled.exe already running (pid " + (($existing | ForEach-Object { $_.ProcessId }) -join ',') + "). Stop it first."
    exit 3
}
# 2. Remove the old trace so -ScriptTime cannot match an earlier run.
Remove-Item (Join-Path $run "jfg_trace.log") -ErrorAction SilentlyContinue

# 3. Launch and bind to the game PID (child of the cmd.exe wrapper we started).
$gamePid = $null; $cmd = $null
for ($try = 0; $try -lt 3 -and -not $gamePid; $try++) {
    $cmd = Start-Process -FilePath "cmd.exe" -WorkingDirectory $run -WindowStyle Hidden -PassThru `
        -ArgumentList "/c `"`"$exe`" $consoleArg --start-game $ExtraArgs > `"$log`" 2>&1`""
    for ($i = 0; $i -lt 50 -and -not $gamePid; $i++) {
        Start-Sleep -Milliseconds 100
        $child = Get-GameInstances | Where-Object { $_.ParentProcessId -eq $cmd.Id }
        if ($child) { $gamePid = [int]($child | Select-Object -First 1).ProcessId }
    }
    if (-not $gamePid) { "launch attempt ${try}: no game process under cmd pid $($cmd.Id) within 5 s"; Start-Sleep -Seconds 2 }
}
if (-not $gamePid) { "FAILED: game process did not start"; "log: $log"; exit 4 }
"RUN_PID=$gamePid cmd_pid=$($cmd.Id) started=$((Get-Date).ToString('HH:mm:ss.fff'))"
$maxInstances = 1
$duplicate = $false
function Sample-Instances {
    $n = @(Get-GameInstances).Count
    if ($n -gt $script:maxInstances) { $script:maxInstances = $n }
    if ($n -gt 1) { $script:duplicate = $true }
}

if ($WindowSize) {
    Add-Type @"
using System;
using System.Runtime.InteropServices;
public static class RunWin {
    [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L, T, R, B; }
    [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
    [DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h, out RECT r);
    [DllImport("user32.dll")] public static extern bool SetWindowPos(IntPtr h, IntPtr a, int x, int y, int w, int hh, uint f);
    [DllImport("user32.dll")] public static extern bool SetProcessDPIAware();
}
"@
    [void][RunWin]::SetProcessDPIAware()   # sizes in physical pixels
    $w, $h = $WindowSize -split "," | ForEach-Object { [int]$_ }
    $hwnd = [IntPtr]::Zero
    for ($i = 0; $i -lt 300 -and $hwnd -eq [IntPtr]::Zero; $i++) {
        $p = Get-Process -Id $gamePid -ErrorAction SilentlyContinue
        if ($p -and $p.MainWindowHandle -ne [IntPtr]::Zero) { $hwnd = $p.MainWindowHandle } else { Start-Sleep -Milliseconds 100 }
    }
    if ($hwnd -eq [IntPtr]::Zero) { "WINDOW_RESIZE=0 (no window)" }
    else {
        $wr = New-Object RunWin+RECT; $cr = New-Object RunWin+RECT
        [void][RunWin]::GetWindowRect($hwnd, [ref]$wr); [void][RunWin]::GetClientRect($hwnd, [ref]$cr)
        # Window size = client size + frame; SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE.
        $fw = ($wr.R - $wr.L) - ($cr.R - $cr.L); $fh = ($wr.B - $wr.T) - ($cr.B - $cr.T)
        [void][RunWin]::SetWindowPos($hwnd, [IntPtr]::Zero, 0, 0, $w + $fw, $h + $fh, 0x16)
        Start-Sleep -Milliseconds 300
        [void][RunWin]::GetClientRect($hwnd, [ref]$cr)
        "WINDOW_RESIZE=1 client=$($cr.R - $cr.L)x$($cr.B - $cr.T)"
    }
}
$t0 = (Get-Date).AddSeconds(-2)
if ($ScriptTime) {
    $trace = Join-Path $run "jfg_trace.log"
    for ($i = 0; $i -lt 600; $i++) {
        if ((Test-Path $trace) -and ((Get-Item $trace).LastWriteTime -gt $t0) -and (Select-String -Path $trace -Pattern "Scripted input:" -Quiet)) { break }
        Start-Sleep -Milliseconds 100
    }
    $t0 = Get-Date
}
foreach ($s in (($Shots -split ",") | ForEach-Object { [int]$_ } | Sort-Object)) {
    $wait = $s - ((Get-Date) - $t0).TotalSeconds
    if ($wait -gt 0) { Start-Sleep -Milliseconds ([int]($wait * 1000)) }
    Sample-Instances
    if (-not (Get-Process -Id $gamePid -ErrorAction SilentlyContinue)) { "process gone at $s s"; break }
    & powershell -ExecutionPolicy Bypass -File $winshot (Join-Path $out "shot_${stamp}_$s.png") -ProcessId $gamePid
}
$wait = $Seconds - ((Get-Date) - $t0).TotalSeconds
if ($wait -gt 0) { Start-Sleep -Milliseconds ([int]($wait * 1000)) }
Sample-Instances
if (Get-Process -Id $gamePid -ErrorAction SilentlyContinue) { "RUNNING after $Seconds s - stopping pid $gamePid"; Stop-Process -Id $gamePid -Force }
else { "process ended before $Seconds s" }
Start-Sleep -Seconds 1
"max_instances_seen=$maxInstances"
"log: $log"
if ($duplicate) { "RUN_VALID=0 (more than one JFGRecompiled.exe running during the run)"; exit 5 }
"RUN_VALID=1"
exit 0
