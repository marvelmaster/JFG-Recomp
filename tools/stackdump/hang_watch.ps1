# Run next to tools\run_to_goldwood.ps1 (needs JFG_HEARTBEAT=1, which that script sets): when jfg_trace.log stops
# changing for 5 s while JFGRecompiled runs, dumps native stacks of all threads twice, 2 s apart, to
# tools\stackdump\hang_<Tag>.txt / hang_<Tag>2.txt, resolved with the linker map to hang_<Tag>_r.txt / hang_<Tag>2_r.txt.
# Rebuild stackdump.exe from stackdump.cpp with a VS x64 prompt: cl /O1 /EHsc stackdump.cpp
param([string]$Tag = "a")
$d = $PSScriptRoot
$log = Join-Path $PSScriptRoot "..\..\build-cmake\run-jfg\jfg_trace.log"
Start-Sleep 20
for ($i = 0; $i -lt 300; $i++) {
    Start-Sleep 1
    $p = Get-Process JFGRecompiled -ErrorAction SilentlyContinue
    if (-not $p) { "process gone"; exit }
    $age = ((Get-Date) - (Get-Item $log).LastWriteTime).TotalSeconds
    if ($age -gt 5) {
        "STALL detected age=$age"
        & "$d\stackdump.exe" $p.Id > "$d\hang_$Tag.txt"
        Start-Sleep 2
        & "$d\stackdump.exe" $p.Id > "$d\hang_${Tag}2.txt"
        python "$d\resolve.py" "$d\hang_$Tag.txt" > "$d\hang_${Tag}_r.txt"
        python "$d\resolve.py" "$d\hang_${Tag}2.txt" > "$d\hang_${Tag}2_r.txt"
        "dumped"; exit
    }
}
"no stall"
