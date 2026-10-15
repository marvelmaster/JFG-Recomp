# Debug quick start test: runs JFGRecompiled with --jfg-level (and optionally --jfg-skip-cutscenes) and the
# scripted title/menu route. Reports the script time of the level redirect (0x16D -> level), keeps the stderr run
# log, the trace and the screenshots per run. Menus are still scripted (this is not a menu-free start yet).
# Usage: powershell -ExecutionPolicy Bypass -File tools\test_debug_start.ps1 [-Runs 1] [-Level goldwood] [-SkipCutscenes]
param([int]$Runs = 1, [string]$Level = "goldwood", [switch]$SkipCutscenes, [int]$Seconds = 110, [string]$Shots = "90,105")
$root = Split-Path -Parent $PSScriptRoot
$outDir = Join-Path $root "runlogs"
# Same title/menu route as run_to_goldwood.ps1, up to the character select (the redirect fires at about 62 s).
$script = "21000:START:300,24000:START:300,28000:A:300,32000:A:300," +
          "34000:DOWN:150,34800:DOWN:150,35600:DOWN:150,36400:DOWN:150,38000:A:300," +
          "45000:START:300,52000:START:300,58000:A:300,62000:A:300,66000:A:300"
$extra = "--jfg-level $Level"
if ($SkipCutscenes) { $extra += " --jfg-skip-cutscenes" }
for ($n = 1; $n -le $Runs; $n++) {
    if (Get-Process JFGRecompiled -ErrorAction SilentlyContinue) { throw "Stop the existing JFG instance first." }
    $capture = powershell -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot "run_capture.ps1") -Seconds $Seconds -Shots $Shots `
        -NoConsole -ScriptTime -ExtraArgs $extra -Env "JFG_HEARTBEAT=1;JFG_TRACE_LEVEL=1;JFG_INPUT_SCRIPT=$script"
    $stillRunning = [bool]($capture -match "RUNNING after")
    $latest = Get-ChildItem (Join-Path $outDir "run_*.log") | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    $tag = "debug_start_$Level" + $(if ($SkipCutscenes) { "_skipcs" } else { "" }) + "_$n"
    Copy-Item $latest.FullName (Join-Path $outDir "$tag.stderr.log") -Force
    Copy-Item (Join-Path $root "build-cmake\run-jfg\jfg_trace.log") (Join-Path $outDir "$tag.trace.log") -Force
    $redirect = Select-String -Path (Join-Path $outDir "$tag.stderr.log") -Pattern "redirected to level" | Select-Object -First 1
    if ($redirect -and $redirect.Line -match "script ms (\d+)") { $at = $Matches[1] } else { $at = "n/a" }
    "run $n : redirect at script ms = $at ; still running at script end = $stillRunning ; log = runlogs\$tag.stderr.log"
}
