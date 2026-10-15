@echo off
setlocal
set "JFG_START="
if "%2"=="start" set "JFG_START=--start-game"
cd /d "%~dp0"
if not exist "build-cmake\JFGRecompiled.exe" (
    echo JFGRecompiled.exe fehlt. Zuerst build_jfg.bat ausfuehren.
    exit /b 1
)
if "%1"=="test" (
    if not exist "build-cmake\run-jfg\portable.txt" (
        echo Die vorbereitete portable Testumgebung fehlt.
        exit /b 1
    )
    cd /d "%~dp0build-cmake\run-jfg"
    "%~dp0build-cmake\JFGRecompiled.exe" --show-console %JFG_START%
) else (
    "%~dp0build-cmake\JFGRecompiled.exe" --show-console
)
exit /b %errorlevel%
