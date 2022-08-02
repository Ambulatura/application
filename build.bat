@echo off

IF NOT EXIST build mkdir build
pushd build

call vcvarsall.bat x64

set win32_defines=/DWIN32 /DWIN32_LEAN_AND_MEAN

set common_compiler_flags=/TC /Od /Zi /MT /c /Fo /FC /nologo /Wall %win32_defines% /fsanitize=address

REM /clang:-pedantic /clang:-std=c89

set compiler=clang-cl

if %compiler%==clang-cl (
   set linker=lld-link
   set ar=llvm-lib
   set clang_compiler_flags=/clang:-std=c99 /clang:-pedantic /clang:-fdiagnostics-format=clang /clang:-fdiagnostics-absolute-paths /clang:-fno-omit-frame-pointer
) else (
     if %compiler%==cl (
     	set linker=link
	set ar=lib
     )
)

set common_includes=/I..\source\common\includes\
set win32_includes=/I..\source\win32\includes\
set os_includes=/I..\source\os\includes\

set all_includes=%common_includes% %win32_includes% %os_includes%

%compiler% %common_compiler_flags% %clang_compiler_flags% %os_includes% %common_includes% ..\source\application.c ..\source\common\memory.c

%compiler% %common_compiler_flags% %clang_compiler_flags% %all_includes% ..\source\os\os_memory.c ..\source\os\os_window.c ..\source\os\os_timer.c ..\source\os\os.c ..\source\win32\win32_timer.c ..\source\win32\win32_memory.c ..\source\win32\win32.c

%ar% memory.obj os_memory.obj os_window.obj os_timer.obj os.obj win32_timer.obj win32_memory.obj win32.obj /out:os.lib

%linker% /debug application.obj memory.obj /out:application.exe os.lib User32.lib Winmm.lib /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup /wholearchive:clang_rt.asan-x86_64.lib

IF NOT EXIST binaries mkdir binaries
pushd binaries

del /F /Q *
move ..\*.obj .
move ..\*.lib .

popd

popd
