# 30/60 Hz A/B measurement on the fast Goldwood start (--jfg-test-start goldwood, 0x5C in < 1 s game time).
# Identical wall-clock input (JFG_INPUT_SCRIPT): C-Up at 1.0 s and 2.6 s (two standing jumps in the flat start pool;
# the fresh default game uses the control mode with jump on C-Up), then UP 4.0-7.0 s (walk).
# The persisted option is overridden with JFG_60HZ_GAMEPLAY=0/1. Every run goes through run_capture.ps1 (PID-bound,
# RUN_VALID=1 and max_instances_seen=1 required) and is evaluated with tools/analyze_60hz.py (per real second).
# Saves are checked by name + SHA256 before/after.
# Usage: powershell -ExecutionPolicy Bypass -File tools\test_60hz_ab.ps1 [-Modes "0,1"] [-Runs 1] [-NoAudio] [-Env "X=1"]
param([string]$Modes = "0,1", [int]$Runs = 1, [switch]$NoAudio, [string]$Env = "", [int]$Seconds = 11,
      [string]$InputScript = "1000:CU:150,2600:CU:150,4000:UP:3000", [string]$Analyze = "--walk 4500,6500 --jumps 1000,2600")
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$outDir = Join-Path $root "runlogs"
$runDir = Join-Path $root "build-cmake\run-jfg"
$saveDir = Join-Path $runDir "saves"
function Get-SaveState {
    $h = @{}
    if (Test-Path $saveDir) { Get-ChildItem $saveDir -File | ForEach-Object { $h[$_.Name] = (Get-FileHash $_.FullName -Algorithm SHA256).Hash } }
    return $h
}
$overall = 0
for ($n = 1; $n -le $Runs; $n++) {
    foreach ($mode in ($Modes -split ",")) {
        $tag = "ab60_m${mode}_$n"
        $before = Get-SaveState
        $envs = "JFG_60HZ_GAMEPLAY=$mode;JFG_TRACE_GAMEPLAY=1;JFG_TRACE_LEVEL=1;JFG_INPUT_SCRIPT=$InputScript"
        if ($NoAudio) { $envs += ";JFG_NO_AUDIO=1" }
        if ($Env) { $envs += ";$Env" }
        $capture = @(& powershell -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot "run_capture.ps1") -Seconds $Seconds `
            -Shots "3" -NoConsole -ScriptTime -ExtraArgs "--jfg-test-start goldwood" -Env $envs)
        $after = Get-SaveState
        $valid = ($capture | Where-Object { $_ -match "^RUN_VALID=" } | Select-Object -Last 1)
        $maxi = ($capture | Where-Object { $_ -match "^max_instances_seen=" } | Select-Object -Last 1)
        $alive = [bool]($capture -match "^RUNNING after")
        $logLine = ($capture | Where-Object { $_ -match "^log: " } | Select-Object -Last 1)
        $changed = @(@($before.Keys) + @($after.Keys) | Select-Object -Unique | Where-Object { $before[$_] -ne $after[$_] })
        $trace = Join-Path $outDir "$tag.trace.log"
        $src = Join-Path $runDir "jfg_trace.log"
        if (Test-Path $src) { Copy-Item $src $trace -Force } else { Set-Content $trace "" }
        $res = & python (Join-Path $PSScriptRoot "analyze_60hz.py") $trace @($Analyze -split " ")
        $ok = ($valid -eq "RUN_VALID=1") -and ($maxi -eq "max_instances_seen=1") -and $alive -and ($changed.Count -eq 0)
        if (-not $ok) { $overall = 1 }
        "run $n mode=$mode [$(if ($ok) { 'VALID' } else { 'INVALID' })] $valid $maxi alive=$alive saves_changed=$($changed.Count) $logLine"
        "  $res"
    }
}
exit $overall
