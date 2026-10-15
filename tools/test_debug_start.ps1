# Debug start test. Starts a fresh JFGRecompiled with --jfg-level <level> through the scripted title/menu route
# (the menu part is still scripted: this is NOT a menu-free start), then checks:
#   - the redirect fired and the level the game loaded afterwards (JFG_LEVEL trace)
#   - gameplay updates and player positions exist after the walk starts (JFG_GAMEPLAY / JFG_PLAYER trace)
#   - the player moved (XYZ before/after the scripted walk)
#   - the save file hashes are unchanged (no unintended save writes)
#   - a screenshot exists
# Exit code: 0 = PASS, 1 = FAIL, 2 = error. A still-running process alone is NOT a pass.
# Usage: powershell -ExecutionPolicy Bypass -File tools\test_debug_start.ps1 [-Runs 1] [-Level goldwood] [-Seconds 130]
param([int]$Runs = 1, [string]$Level = "goldwood", [int]$Seconds = 130)
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$outDir = Join-Path $root "runlogs"
$saveDir = Join-Path $root "build-cmake\run-jfg\saves"
New-Item -ItemType Directory -Force $outDir | Out-Null
# Title/menu route as in run_to_goldwood.ps1 up to character select (the redirect fires near 62-66 s). After that the
# game runs its own landing sequence; the walk is scripted at 112 s and checked at the end.
$script = "21000:START:300,24000:START:300,28000:A:300,32000:A:300," +
          "34000:DOWN:150,34800:DOWN:150,35600:DOWN:150,36400:DOWN:150,38000:A:300," +
          "45000:START:300,52000:START:300,58000:A:300,62000:A:300,66000:A:300," +
          "112000:UP:2500,116000:RIGHT:1000"
function Get-SaveHashes {
    if (-not (Test-Path $saveDir)) { return @{} }
    $h = @{}
    Get-ChildItem $saveDir -File | ForEach-Object { $h[$_.Name] = (Get-FileHash $_.FullName -Algorithm SHA256).Hash }
    return $h
}
$overall = 0
for ($n = 1; $n -le $Runs; $n++) {
    if (Get-Process JFGRecompiled -ErrorAction SilentlyContinue) { Write-Host "Stop the existing JFG instance first."; exit 2 }
    $tag = "debug_start_${Level}_$n"
    $before = Get-SaveHashes
    $capture = powershell -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot "run_capture.ps1") -Seconds $Seconds -Shots "95,118" `
        -NoConsole -ScriptTime -ExtraArgs "--jfg-level $Level" `
        -Env "JFG_HEARTBEAT=1;JFG_TRACE_LEVEL=1;JFG_TRACE_GAMEPLAY=1;JFG_INPUT_SCRIPT=$script"
    $after = Get-SaveHashes
    $stderrLog = Get-ChildItem (Join-Path $outDir "run_*.log") | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    Copy-Item $stderrLog.FullName (Join-Path $outDir "$tag.stderr.log") -Force
    Copy-Item (Join-Path $root "build-cmake\run-jfg\jfg_trace.log") (Join-Path $outDir "$tag.trace.log") -Force
    $trace = Get-Content (Join-Path $outDir "$tag.trace.log")
    $err = @()

    # 1. redirect and level
    $redir = $trace | Select-String -Pattern "JFG_LEVEL" | ForEach-Object { $_.Line }
    $stderrText = Get-Content (Join-Path $outDir "$tag.stderr.log")
    $redirectLine = $stderrText | Where-Object { $_ -match "redirected to level" } | Select-Object -First 1
    if (-not $redirectLine) { $err += "no level redirect" }
    $redirectMs = if ($redirectLine -match "script ms (\d+)") { [int64]$Matches[1] } else { -1 }
    $loadedAfter = $redir | Where-Object { $_ -match "level=0x([0-9A-F]+) char=(\d+)" } | Select-Object -Skip 0
    $loaded = $null
    foreach ($l in $redir) { if ($l -match "level=0x([0-9A-F]+) char=(\d+)") { if ([Convert]::ToInt32($Matches[1],16) -eq 0x5D) { $loaded = "0x5D char $($Matches[2])" } } }
    if (-not $loaded) { $err += "level 0x5D never loaded" }

    # 2. gameplay frames and player positions with script time
    $frameMs = @{}
    foreach ($l in $trace) { if ($l -match "JFG_GAMEPLAY frame=(\d+) ms=(\d+)") { $frameMs[[int]$Matches[1]] = [int64]$Matches[2] } }
    $players = @()
    foreach ($l in $trace) { if ($l -match "JFG_PLAYER frame=(\d+) xyz=([-\d\.]+),([-\d\.]+),([-\d\.]+)") {
        $f = [int]$Matches[1]; if ($frameMs.ContainsKey($f)) { $players += [pscustomobject]@{ ms = $frameMs[$f]; x = [double]$Matches[2]; y = [double]$Matches[3]; z = [double]$Matches[4] } } } }
    $late = $players | Where-Object { $_.ms -ge 100000 }
    $firstPlayerMs = if ($players.Count) { $players[0].ms } else { -1 }
    if (-not $late -or $late.Count -lt 2) { $err += "no player positions after 100 s" }

    # 3. movement
    $dist = 0.0
    if ($late -and $late.Count -ge 2) {
        $a = $late[0]; $b = $late[-1]
        $dist = [math]::Sqrt([math]::Pow($b.x-$a.x,2) + [math]::Pow($b.y-$a.y,2) + [math]::Pow($b.z-$a.z,2))
        if ($dist -lt 0.5) { $err += "player did not move (distance $([math]::Round($dist,3)))" }
    }

    # 4. saves unchanged
    $saveChanged = @()
    foreach ($k in @($before.Keys + $after.Keys | Select-Object -Unique)) { if ($before[$k] -ne $after[$k]) { $saveChanged += $k } }
    if ($saveChanged.Count) { $err += "save files changed: $($saveChanged -join ', ')" }

    # 5. screenshot and crash markers
    $shot = Get-ChildItem (Join-Path $outDir "shot_*_118.png") -ErrorAction SilentlyContinue | Sort-Object LastWriteTime | Select-Object -Last 1
    if (-not $shot) { $err += "no screenshot" }
    if ($capture -match "process gone") { $err += "process exited early" }

    $status = if ($err.Count -eq 0) { "PASS" } else { "FAIL"; $overall = 1 }
    "run $n [$status] level=$loaded redirect_script_ms=$redirectMs first_player_ms=$firstPlayerMs " +
        "walk_distance=$([math]::Round($dist,3)) saves_changed=$($saveChanged.Count) log=runlogs\$tag.stderr.log"
    foreach ($e in $err) { "   - $e" }
    if (Get-Process JFGRecompiled -ErrorAction SilentlyContinue) { Stop-Process -Name JFGRecompiled -Force }
}
exit $overall
