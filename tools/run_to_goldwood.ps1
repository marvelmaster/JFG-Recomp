# Scripted smoke test: boot -> title -> PLAY -> Game 1 / New Game -> label "1" -> END -> skip intro cutscene
# -> Juno briefing -> Goldwood, then walk/jump/turn/fire. Timings are wall-clock ms from the first pad poll
# (verified 2026-10-15 on the dev PC; gameplay starts at ~105 s). Screenshots go to runlogs\.
# Usage: powershell -ExecutionPolicy Bypass -File tools\run_to_goldwood.ps1 [-Seconds 124] [-Shots "111,116,123"] [-Env "K=V"]
param([int]$Seconds = 124, [string]$Shots = "45,70,111,116,121,123", [string]$Env = "")
$script = "21000:START:300,24000:START:300,28000:A:300,32000:A:300," +
          "34000:DOWN:150,34800:DOWN:150,35600:DOWN:150,36400:DOWN:150,38000:A:300," +
          "45000:START:300,52000:START:300,58000:A:300,62000:A:300,66000:A:300," +
          "112000:UP:2500,115800:A:200,117000:RIGHT:1500,120000:Z:800"
$allEnv = "JFG_HEARTBEAT=1;JFG_TRACE_INPUT=1;JFG_INPUT_SCRIPT=$script"
if ($Env) { $allEnv = "$allEnv;$Env" }
& powershell -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot "run_capture.ps1") -Seconds $Seconds -Shots $Shots -NoConsole -Env $allEnv
