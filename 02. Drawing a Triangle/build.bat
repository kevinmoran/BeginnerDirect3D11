@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64

set COMPILER_FLAGS=/MTd /nologo /Gm- /EHa- /GR- /fp:fast /Od /Oi /W4 /wd4201 /wd4100 /wd4189 /wd4514 /wd4820 /wd4505 /FC /Z7

set LINKER_FLAGS=/INCREMENTAL:NO /opt:ref
set SYSTEM_LIBS=user32.lib gdi32.lib winmm.lib d3d11.lib d3dcompiler.lib

SET BUILD_DIR=".\build"
if not exist %BUILD_DIR% mkdir %BUILD_DIR%
pushd %BUILD_DIR%

cl %COMPILER_FLAGS% ../main.cpp /Fmmain.map /link %LINKER_FLAGS% %SYSTEM_LIBS%

popd
echo Done