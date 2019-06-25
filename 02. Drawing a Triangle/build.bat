@echo off

REM NOTE: Uncomment whichever one that you have installed!
REM call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x64
REM call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x64
REM call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x64
REM call "C:\Program Files (x86)\Microsoft Visual Studio 13.0\VC\vcvarsall.bat" x64
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
REM call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x64

set COMMON_COMPILER_FLAGS=/nologo /EHa- /GR- /fp:fast /Oi /W4 /wd4100 /FC /Fm

set DEBUG_FLAGS=/DDEBUG_BUILD /Od /MTd /Z7
set RELEASE_FLAGS =/O2

set COMPILER_FLAGS=%COMMON_COMPILER_FLAGS% %DEBUG_FLAGS%
REM set COMPILER_FLAGS=%COMMON_COMPILER_FLAGS% %RELEASE_FLAGS%

set LINKER_FLAGS=/INCREMENTAL:NO /opt:ref
set SYSTEM_LIBS=user32.lib gdi32.lib winmm.lib d3d11.lib d3dcompiler.lib

set BUILD_DIR=".\build"
if not exist %BUILD_DIR% mkdir %BUILD_DIR%
pushd %BUILD_DIR%

cl %COMPILER_FLAGS% ../main.cpp /link %LINKER_FLAGS% %SYSTEM_LIBS%

popd
echo Done