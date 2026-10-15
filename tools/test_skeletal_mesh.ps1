# Character-mesh regression on the fast Goldwood start (--jfg-test-start goldwood, 30 Hz forced unless -Mode60).
# Input (wall clock from the first pad poll): C-Up at 1.0 s (jump in the start pool), RIGHT 2.0-2.8 s (turn),
# UP 3.5-10.5 s (run; after the turn Juno runs along the pool wall, seen from the side).
# Screenshots of this run's PID at 1.25 s (jump), 2.5 s (turn), 5 s (run from behind), 13 s (side view).
# Technical assertion: JFG_CAPTURE_DL=<dl> captures one display list (default 761 = main pass at about 13 s; the even DL before it is a 64x64 off-screen pass) and
# tools/check_jfg_capture.py requires one common GPU x scale per model and viewport (no "sliced" models) and equal y/w.
# PASS needs: RUN_VALID=1, max_instances_seen=1, process alive until the end, saves unchanged (names + SHA256),
# all screenshots of this run present, capture files present and the capture check PASS.
# -Aspect Expand|Original: ar_option for the run (graphics.json of the run folder is restored afterwards, hash-checked).
# -WindowSize "W,H": window client size (default window 1600x900 = 16:9), e.g. "1890,810" for 21:9 (physical pixels).
# Usage: powershell -ExecutionPolicy Bypass -File tools\test_skeletal_mesh.ps1 [-Runs 1] [-Dl 761] [-Mode60] [-NoAudio] [-Aspect Original] [-WindowSize 1890,810]
param([int]$Runs = 1, [int]$Dl = 761, [switch]$Mode60, [switch]$NoAudio, [ValidateSet("Expand", "Original")][string]$Aspect = "Expand", [string]$WindowSize = "")
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$runDir = Join-Path $root "build-cmake\run-jfg"
$saveDir = Join-Path $runDir "saves"
$graphics = Join-Path $runDir "graphics.json"
$shotTimes = @(1, 2, 5, 13)
function Get-SaveState {
    $h = @{}
    if (Test-Path $saveDir) { Get-ChildItem $saveDir -File | ForEach-Object { $h[$_.Name] = (Get-FileHash $_.FullName -Algorithm SHA256).Hash } }
    return $h
}
$graphicsText = [System.IO.File]::ReadAllText($graphics)
$graphicsHash = (Get-FileHash $graphics -Algorithm SHA256).Hash
if ($graphicsText -notmatch '"ar_option": "Expand"') { "graphics.json ar_option is not Expand - refusing to change it"; exit 1 }
$overall = 0
try {
    if ($Aspect -ne "Expand") { [System.IO.File]::WriteAllText($graphics, $graphicsText.Replace('"ar_option": "Expand"', "`"ar_option`": `"$Aspect`"")) }
    for ($n = 1; $n -le $Runs; $n++) {
        $capDir = Join-Path $runDir "jfg_capture_$Dl"
        if (Test-Path $capDir) { Remove-Item -Recurse -Force -LiteralPath $capDir }
        foreach ($f in @("jfg_commands_$Dl.txt", "jfg_rdram_$Dl.bin")) { $p = Join-Path $runDir $f; if (Test-Path $p) { Remove-Item -Force -LiteralPath $p } }
        $before = Get-SaveState
        $mode = if ($Mode60) { "1" } else { "0" }
        $envs = "JFG_60HZ_GAMEPLAY=$mode;JFG_CAPTURE_DL=$Dl;JFG_INPUT_SCRIPT=1000:CU:150,2000:RIGHT:800,3500:UP:7000"
        if ($NoAudio) { $envs += ";JFG_NO_AUDIO=1" }
        $runArgs = @("-Seconds", "15", "-Shots", ($shotTimes -join ","), "-NoConsole", "-ScriptTime", "-ExtraArgs", "--jfg-test-start goldwood", "-Env", $envs)
        if ($WindowSize) { $runArgs += @("-WindowSize", $WindowSize) }
        $capture = @(& powershell -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot "run_capture.ps1") @runArgs)
        $after = Get-SaveState
        $valid = ($capture | Where-Object { $_ -match "^RUN_VALID=" } | Select-Object -Last 1)
        $maxi = ($capture | Where-Object { $_ -match "^max_instances_seen=" } | Select-Object -Last 1)
        $alive = [bool]($capture -match "^RUNNING after")
        $resize = ($capture | Where-Object { $_ -match "^WINDOW_RESIZE=" } | Select-Object -Last 1)
        $logLine = ($capture | Where-Object { $_ -match "^log: " } | Select-Object -Last 1)
        $changed = @(@($before.Keys) + @($after.Keys) | Select-Object -Unique | Where-Object { $before[$_] -ne $after[$_] })
        # Screenshots of this run: runlogs\shot_<stamp>_<s>.png with the stamp of this run's log (run_<stamp>.log).
        $shotsOk = $false
        if ($logLine -match 'run_(\d{4}_\d{9})\.log$') {
            $stamp = $Matches[1]
            $missing = @($shotTimes | Where-Object { -not (Test-Path (Join-Path $root "runlogs\shot_${stamp}_$_.png")) })
            $shotsOk = $missing.Count -eq 0
        }
        $capOk = (Test-Path (Join-Path $runDir "jfg_commands_$Dl.txt")) -and (Test-Path (Join-Path $capDir "after_draw_screen.bin"))
        Push-Location $root
        $check = @(& python (Join-Path $PSScriptRoot "check_jfg_capture.py") $Dl $runDir)
        $checkExit = $LASTEXITCODE
        Pop-Location
        $resizeOk = (-not $WindowSize) -or ($resize -match "^WINDOW_RESIZE=1")
        $ok = ($valid -eq "RUN_VALID=1") -and ($maxi -eq "max_instances_seen=1") -and $alive -and ($changed.Count -eq 0) -and
            $shotsOk -and $capOk -and ($checkExit -eq 0) -and $resizeOk
        if (-not $ok) { $overall = 1 }
        "run $n mode60=$mode aspect=$Aspect window=$(if ($WindowSize) { $resize } else { 'default' }) [$(if ($ok) { 'PASS' } else { 'FAIL' })] $valid $maxi alive=$alive saves_changed=$($changed.Count) shots=$shotsOk capture=$capOk capture_check_exit=$checkExit $logLine"
        $check | ForEach-Object { "  $_" }
    }
}
finally {
    if ((Get-FileHash $graphics -Algorithm SHA256).Hash -ne $graphicsHash) { [System.IO.File]::WriteAllText($graphics, $graphicsText) }
    if ((Get-FileHash $graphics -Algorithm SHA256).Hash -ne $graphicsHash) { "graphics.json NOT restored"; $overall = 1 }
}
exit $overall
