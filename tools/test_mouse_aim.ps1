# Mouse aim smoke test: same route as run_to_goldwood.ps1 to Goldwood, then (script ms from the first pad poll)
#   110 s hold R (aim mode, no mouse)       113 s R + scripted mouse right (10 counts/poll)
#   116 s right mouse button + mouse up     118.5 s RMB + stick LEFT (-> C-left strafe)   121 s RMB + LMB (fire)
# -Tail "ms:KEYS:hold,..." replaces the gameplay part (keys: see main.cpp, plus LMB RMB MLEFT MRIGHT MUP MDOWN).
# Needs the "Mouse Sensitivity" option > 0 (default 100). Look for "[JFG] Mouse aim" in build-cmake\run-jfg\jfg_trace.log.
param([int]$Seconds = 126, [string]$Shots = "111,113,116,118,121,123", [string]$Env = "", [string]$Tail = "")
$script = "21000:START:300,24000:START:300,28000:A:300,32000:A:300," +
          "34000:DOWN:150,34800:DOWN:150,35600:DOWN:150,36400:DOWN:150,38000:A:300," +
          "45000:START:300,52000:START:300,58000:A:300,62000:A:300,66000:A:300," +
          $(if ($Tail) { $Tail } else { "110000:R:2500,113000:R+MRIGHT:2500,116000:RMB+MUP:2000,118500:RMB+LEFT:2000,121000:RMB+LMB:1000" })
$allEnv = "JFG_HEARTBEAT=1;JFG_TRACE_INPUT=1;JFG_INPUT_SCRIPT=$script"
if ($Env) { $allEnv = "$allEnv;$Env" }
& powershell -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot "run_capture.ps1") -Seconds $Seconds -Shots $Shots -NoConsole -ScriptTime -Env $allEnv
