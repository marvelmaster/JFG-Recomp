# Identical wall-clock inputs with the persisted option overridden off/on.
# Walk out of the shallow landing pool before jumping (a jump in the pool
# does not provide a useful jump-height comparison).
param([ValidateSet('0','1','both')][string]$Mode = 'both')
$root = Split-Path -Parent $PSScriptRoot
$modes = if ($Mode -eq 'both') { @('0','1') } else { @($Mode) }
foreach ($value in $modes) {
    if (Get-Process JFGRecompiled -ErrorAction SilentlyContinue) {
        throw 'Stop the existing JFG instance before running the comparison.'
    }
    & powershell -ExecutionPolicy Bypass -File "$PSScriptRoot\test_mouse_aim.ps1" `
        -Seconds 128 -Shots '109,112,115,116,117,118,123' `
        -Tail '110000:UP:1500,116000:A:1000,122000:RMB+LMB:800' `
        -Env "JFG_60HZ_GAMEPLAY=$value;JFG_TRACE_GAMEPLAY=1"
    if ($LASTEXITCODE -ne 0) { throw "Capture failed for mode $value" }
    $trace = Join-Path $root "runlogs\gameplay_compare_$value.log"
    Copy-Item -LiteralPath "$root\build-cmake\run-jfg\jfg_trace.log" -Destination $trace
    & python "$PSScriptRoot\analyze_gameplay.py" $trace
}
