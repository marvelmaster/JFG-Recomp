@echo off
setlocal
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul
if errorlevel 1 exit /b %errorlevel%
set "PATH=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\Llvm\x64\bin;%PATH%"
cd /d "%~dp0"
python tools\test_jfg_projective_matrix.py
exit /b %errorlevel%
