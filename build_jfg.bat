@echo off
setlocal
rem NOTE: RT64 (plume_d3d12.cpp) wants Windows SDK 10.0.26100 (D3D12_HEAP_TYPE_GPU_UPLOAD); with SDK 22621 the
rem enum value is supplied by hand via CMAKE_CXX_FLAGS below. Remove that once the newer SDK is installed.
rem Configure + build JFGRecompiled with VS 2022 clang-cl + Ninja.  Usage: build_jfg.bat [configure|build]
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul
if errorlevel 1 exit /b %errorlevel%
set PATH=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\Llvm\x64\bin;%PATH%
rem Use the real executables, avoiding Python launchers that inspect unrelated package files.
set "JFG_CMAKE=%LOCALAPPDATA%\Programs\Python\Python311\Lib\site-packages\cmake\data\bin\cmake.exe"
if not exist "%JFG_CMAKE%" set "JFG_CMAKE=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
set "JFG_NINJA=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja\ninja.exe"
cd /d "%~dp0"
if "%1"=="build" goto build
"%JFG_CMAKE%" -S . -B build-cmake -G Ninja "-DCMAKE_MAKE_PROGRAM=%JFG_NINJA%" -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_BUILD_TYPE=Release "-DCMAKE_CXX_FLAGS=/DWIN32 /D_WINDOWS /GR /EHsc /DD3D12_HEAP_TYPE_GPU_UPLOAD=((D3D12_HEAP_TYPE)5)" > configure.log 2>&1
set "JFG_RESULT=%errorlevel%"
echo configure exit=%JFG_RESULT%
if not "%JFG_RESULT%"=="0" exit /b %JFG_RESULT%
if "%1"=="configure" goto end
:build
"%JFG_CMAKE%" --build build-cmake --target BanjoRecompiled -j 12 > build.log 2>&1
set "JFG_RESULT=%errorlevel%"
echo build exit=%JFG_RESULT%
:end
exit /b %JFG_RESULT%
