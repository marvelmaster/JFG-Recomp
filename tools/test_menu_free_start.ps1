# Menu-free start test: JFGRecompiled --jfg-test-start goldwood | goldwood-full (no title/menu input at all).
#   goldwood (fast, default): 0x5C requested at the main loop's first level-0 request (about 0.5 s after boot).
#     Input: UP held from 0.2 s to 10.2 s script time, so the first frame in which input moves the player is measured
#     directly (the input is already held when 0x5C loads).
#   goldwood-full: title request replaced, the game plays 0x16D -> 0x5D -> 0x5C itself (0x5C at about 50 s).
#     Input: UP held 0.4 s every second from 30 s to 69 s (first move resolution 1 s).
#   Walking forward reaches Magnus, whose welcome dialogue of a fresh game then waits for A (normal game behaviour).
# Per run it checks (all from this run's PID-bound log, trace and screenshot, see run_capture.ps1):
#   - RUN_VALID=1 and max_instances_seen=1, the process was still running at the end (no crash/exit)
#   - the test start fired ("--jfg-test-start:" line); no title level 0x15D; goldwood: no 0x16D/0x5D either
#   - the ACTIVE level (levelInit, not only the request) reaches 0x5C "Forest Day Landing" with char 1 (Juno)
#   - objSetupPlayers ran for 0x5C, player positions exist after it, the player moved horizontally > 1 unit
#   - save folder unchanged: no file created, deleted or renamed, same SHA256 hashes
#   - the screenshot of this run (shot_<run stamp>_<s>.png) exists
# Times: script ms (first pad poll) and process ms (SDL ticks since SDL init, about process start).
# With -Normal the run is made WITHOUT the flag and must reach the title (0x15D) without a test start.
# Exit code: 0 = all runs PASS, 1 = a run failed, 2 = harness error.
# Usage: powershell -ExecutionPolicy Bypass -File tools\test_menu_free_start.ps1 [-Runs 10] [-Seconds 12]
#        [-Start goldwood|goldwood-full] [-Normal] [-EnvExtra "NAME=value"]
param([int]$Runs = 1, [int]$Seconds = 0, [switch]$Normal, [string]$Start = "goldwood", [string]$EnvExtra = "")
$fast = (-not $Normal) -and $Start -eq "goldwood"
if ($Seconds -le 0) { $Seconds = if ($fast) { 12 } elseif ($Normal) { 40 } else { 75 } }
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$outDir = Join-Path $root "runlogs"
$runDir = Join-Path $root "build-cmake\run-jfg"
$saveDir = Join-Path $runDir "saves"
New-Item -ItemType Directory -Force $outDir | Out-Null
$walk = if ($fast) { "200:UP:10000" } else { (30..69 | ForEach-Object { "$($_ * 1000):UP:400" }) -join "," }
$shotAt = if ($fast) { 2 } else { $Seconds - 5 }
function Get-SaveState {
    $h = @{}
    if (Test-Path $saveDir) { Get-ChildItem $saveDir -File | ForEach-Object { $h[$_.Name] = (Get-FileHash $_.FullName -Algorithm SHA256).Hash } }
    return $h
}
$overall = 0
for ($n = 1; $n -le $Runs; $n++) {
    $tag = if ($Normal) { "normal_start_$n" } else { "menu_free_${Start}_$n" }
    $before = Get-SaveState
    # powershell -File drops an empty argument, so -ExtraArgs is only passed when there is something to pass.
    $captureArgs = @("-ExecutionPolicy", "Bypass", "-File", (Join-Path $PSScriptRoot "run_capture.ps1"), "-Seconds", $Seconds,
        "-Shots", "$shotAt", "-NoConsole", "-ScriptTime",
        "-Env", "JFG_HEARTBEAT=1;JFG_TRACE_LEVEL=1;JFG_TRACE_GAMEPLAY=1;$EnvExtra;JFG_INPUT_SCRIPT=$walk")
    if (-not $Normal) { $captureArgs += @("-ExtraArgs", "--jfg-test-start $Start") }
    $capture = @(& powershell @captureArgs)
    $captureExit = $LASTEXITCODE
    $after = Get-SaveState
    $err = @()
    $logLine = $capture | Where-Object { $_ -match "^log: (.+)$" } | Select-Object -Last 1
    $pidLine = $capture | Where-Object { $_ -match "^RUN_PID=(\d+)" } | Select-Object -First 1
    $validLine = $capture | Where-Object { $_ -match "^RUN_VALID=" } | Select-Object -Last 1
    $maxLine = $capture | Where-Object { $_ -match "^max_instances_seen=" } | Select-Object -Last 1
    if (-not $logLine -or -not $pidLine) { "run $n : harness error (exit $captureExit): $($capture -join ' | ')"; $overall = 2; continue }
    if ($validLine -ne "RUN_VALID=1" -or $maxLine -ne "max_instances_seen=1") { $err += "run invalid: $validLine $maxLine (exit $captureExit)" }
    $ownLog = ($logLine -replace "^log: ", "").Trim()
    $runPid = [int]($pidLine -replace "^RUN_PID=(\d+).*$", '$1')
    Copy-Item $ownLog (Join-Path $outDir "$tag.stderr.log") -Force
    # A missing trace (e.g. the game stopped at a modal box before its first frame) is a FAIL of this run, not a script abort.
    $traceSrc = Join-Path $runDir "jfg_trace.log"
    if (Test-Path $traceSrc) { Copy-Item $traceSrc (Join-Path $outDir "$tag.trace.log") -Force }
    else { Set-Content (Join-Path $outDir "$tag.trace.log") ""; $err += "no jfg_trace.log (game did not reach its first frame)" }
    $stderrText = @(Get-Content (Join-Path $outDir "$tag.stderr.log"))
    $trace = @(Get-Content (Join-Path $outDir "$tag.trace.log"))

    # 1. test start fired (or, with -Normal, did not)
    $ts = $stderrText | Where-Object { $_ -match "--jfg-test-start: new default game" } | Select-Object -First 1
    if ($Normal -and $ts) { $err += "normal start shows a test start" }
    if (-not $Normal -and -not $ts) { $err += "test start did not fire" }

    # 2. active levels (levelInit), first 0x5C load
    $inits = @()
    foreach ($l in $trace) { if ($l -match "JFG_LEVELINIT ms=(\d+) ticks=(\d+) level=0x([0-9A-F]+) a1=-?\d+ char=(-?\d+)") {
        $inits += [pscustomobject]@{ ms = [int64]$Matches[1]; ticks = [int64]$Matches[2]; level = [Convert]::ToInt32($Matches[3], 16); char = [int]$Matches[4] } } }
    $seq = ($inits | ForEach-Object { "0x{0:X}" -f $_.level }) -join ","
    $landing = $inits | Where-Object { $_.level -eq 0x5C } | Select-Object -First 1
    if ($Normal -and -not ($inits | Where-Object { $_.level -eq 0x15D })) { $err += "normal start did not reach the title level 0x15D (sequence $seq)" }
    if ($Normal -and ($inits | Where-Object { $_.level -eq 0x16D })) { $err += "normal start loaded 0x16D without menu input" }
    if (-not $Normal) {
        if ($inits | Where-Object { $_.level -eq 0x15D }) { $err += "title level 0x15D was loaded" }
        if ($fast -and ($inits | Where-Object { $_.level -eq 0x16D -or $_.level -eq 0x5D })) { $err += "fast start loaded a cutscene level ($seq)" }
        if (-not $landing) { $err += "level 0x5C never became active (sequence $seq)" }
        elseif ($landing.char -ne 1) { $err += "0x5C loaded with char $($landing.char)" }
    }

    # 3. player setup and first controllable frame after 0x5C
    $frameMs = @{}
    foreach ($l in $trace) { if ($l -match "JFG_GAMEPLAY frame=(\d+) ms=(\d+)") { $frameMs[[int]$Matches[1]] = [int64]$Matches[2] } }
    $players = @()
    foreach ($l in $trace) { if ($l -match "JFG_PLAYER frame=(\d+) xyz=([-\d\.]+),([-\d\.]+),([-\d\.]+)") {
        $f = [int]$Matches[1]; if ($frameMs.ContainsKey($f)) { $players += [pscustomobject]@{ ms = $frameMs[$f]; x = [double]$Matches[2]; y = [double]$Matches[3]; z = [double]$Matches[4] } } } }
    $firstMoveMs = -1; $dist = 0.0
    if ($landing) {
        $setup = $trace | Where-Object { $_ -match "JFG_SETUPPLAYERS ms=(\d+)" } | ForEach-Object { [int64]([regex]::Match($_, "ms=(\d+)").Groups[1].Value) } |
            Where-Object { $_ -ge $landing.ms } | Select-Object -First 1
        if (-not $setup) { $err += "objSetupPlayers not called for 0x5C" }
        $late = @($players | Where-Object { $_.ms -ge $landing.ms })
        if ($late.Count -lt 2) { $err += "no player positions after 0x5C" }
        else {
            $a = $late[0]; $w0 = $null
            foreach ($p in $late) {
                $d = [math]::Sqrt([math]::Pow($p.x - $a.x, 2) + [math]::Pow($p.z - $a.z, 2))
                # first frame after the 0x5C load whose horizontal position differs by > 1 unit from the spawn
                # position (only scripted UP moves the player there; the landing fall changes y only)
                if ($p.ms -ge $landing.ms) {
                    if (-not $w0) { $w0 = $p }
                    $dw = [math]::Sqrt([math]::Pow($p.x - $w0.x, 2) + [math]::Pow($p.z - $w0.z, 2))
                    if ($firstMoveMs -lt 0 -and $dw -gt 1.0) { $firstMoveMs = $p.ms }
                }
                if ($d -gt $dist) { $dist = $d }
            }
            if ($firstMoveMs -lt 0) { $err += "player did not move during the scripted walk after 0x5C" }
        }
    }

    # 4. saves: names and hashes
    $created = @($after.Keys | Where-Object { -not $before.ContainsKey($_) })
    $deleted = @($before.Keys | Where-Object { -not $after.ContainsKey($_) })
    $changed = @($before.Keys | Where-Object { $after.ContainsKey($_) -and $before[$_] -ne $after[$_] })
    if ($created.Count -or $deleted.Count -or $changed.Count) {
        $err += "saves: created=[$($created -join ',')] deleted=[$($deleted -join ',')] changed=[$($changed -join ',')]" }

    # 5. screenshot of this run (same stamp as its log) and early exit
    $stamp = [IO.Path]::GetFileNameWithoutExtension($ownLog) -replace "^run_", ""
    $shot = Get-Item (Join-Path $outDir "shot_${stamp}_$shotAt.png") -ErrorAction SilentlyContinue
    if (-not $shot) { $err += "no screenshot shot_${stamp}_$shotAt.png" }
    if (-not ($capture -match "^RUNNING after")) { $err += "process exited before the end of the run" }

    $status = if ($err.Count -eq 0) { "PASS" } else { "FAIL"; $overall = [math]::Max($overall, 1) }
    $landMs = if ($landing) { $landing.ms } else { -1 }
    $landTicks = if ($landing) { $landing.ticks } else { -1 }
    $moveTicks = if ($landing -and $firstMoveMs -ge 0) { $landing.ticks + ($firstMoveMs - $landing.ms) } else { -1 }
    "run $n [$status] pid=$runPid levels=$seq land_0x5C_ms=$landMs land_0x5C_process_ms=$landTicks first_move_ms=$firstMoveMs " +
        "first_move_process_ms=$moveTicks max_dist=$([math]::Round($dist,1)) " +
        "saves_created=$($created.Count) deleted=$($deleted.Count) changed=$($changed.Count) shot=$(if ($shot) { $shot.Name }) log=runlogs\$tag.stderr.log"
    foreach ($e in $err) { "   - $e" }
}
exit $overall
