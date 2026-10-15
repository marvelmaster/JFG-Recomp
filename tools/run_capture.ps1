# Starts JFGRecompiled (portable test folder, --start-game), captures its console output and takes
# screenshots of the game window (tools\shot_window.ps1, works while covered) at the given seconds, then stops it.
# Usage: powershell -ExecutionPolicy Bypass -File tools\run_capture.ps1 -Seconds 60 -Shots "20,40,60" `
#            [-ExtraArgs "--test-start-button"] [-Env "JFG_TRACE_AUDIO=1;JFG_TRACE_INPUT=1"]
# -ScriptTime: shot times (and -Seconds) count from the first pad poll, i.e. the JFG_INPUT_SCRIPT time base
#   (detected via the "[JFG] Scripted input:" line in jfg_trace.log of the run folder), not from the launch.
param([int]$Seconds = 60, [string]$Shots = "20,40,60", [string]$ExtraArgs = "", [string]$Env = "", [switch]$NoConsole, [switch]$ScriptTime)
foreach ($kv in ($Env -split ";" | Where-Object { $_ })) { $k, $v = $kv -split "=", 2; Set-Item "env:$k" $v }
$root = Split-Path -Parent $PSScriptRoot
$run = Join-Path $root "build-cmake\run-jfg"
$out = Join-Path $root "runlogs"
New-Item -ItemType Directory -Force $out | Out-Null
$stamp = Get-Date -Format "MMdd_HHmmss"
$log = Join-Path $out "run_$stamp.log"
$exe = Join-Path $root "build-cmake\JFGRecompiled.exe"
$winshot = Join-Path $PSScriptRoot "shot_window.ps1"
$consoleArg = if ($NoConsole) { "" } else { "--show-console" }
# The first launch right after a rebuild is sometimes refused ("Access is denied", probably the
# virus scanner still holding the fresh exe). Retry a few times before starting the clock.
for ($try = 0; $try -lt 5; $try++) {
    Start-Process -FilePath "cmd.exe" -WorkingDirectory $run -WindowStyle Hidden `
        -ArgumentList "/c `"`"$exe`" $consoleArg --start-game $ExtraArgs > `"$log`" 2>&1`""
    Start-Sleep -Seconds 2
    if (Get-Process JFGRecompiled -ErrorAction SilentlyContinue) { break }
    "launch attempt $try failed: $(Get-Content $log -TotalCount 1 -ErrorAction SilentlyContinue)"
    Start-Sleep -Seconds 3
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
    if (-not (Get-Process JFGRecompiled -ErrorAction SilentlyContinue)) { "process gone at $s s"; break }
    & powershell -ExecutionPolicy Bypass -File $winshot (Join-Path $out "shot_${stamp}_$s.png")
}
$wait = $Seconds - ((Get-Date) - $t0).TotalSeconds
if ($wait -gt 0) { Start-Sleep -Milliseconds ([int]($wait * 1000)) }
if (Get-Process JFGRecompiled -ErrorAction SilentlyContinue) { "RUNNING after $Seconds s - stopping"; Stop-Process -Name JFGRecompiled -Force }
else { "process ended before $Seconds s" }
Start-Sleep -Seconds 1
"log: $log"
