:: usage: call build.bat "mkspec" "config"
:: eg: call build.bat "win32-icc" "release static_build"
:: IMPORTANT: Double quotation marks are indispensable
cd /d "%~dp0"
if exist build rd /s /q build
md build
cd build
set _mkspec=%1
if defined _mkspec (
    set _mkspec=%_mkspec:~1,-1%
) else (
    where clang-cl
    if %ERRORLEVEL% == 0 set _mkspec=win32-clang-msvc
    where icl
    if %ERRORLEVEL% == 0 set _mkspec=win32-icc
)
if /i "%_mkspec%" == "" set _mkspec=win32-msvc
set _config=%2
if defined _config (
    set _config=%_config:~1,-1%
) else (
    set _config=release
)
qmake "%~dp0dynamic-desktop.pro" -spec %_mkspec% "CONFIG+=%_config%"
set _buildtool=jom
where %_buildtool%
if %ERRORLEVEL% neq 0 set _buildtool=nmake
%_buildtool% qmake_all
%_buildtool% && %_buildtool% install
cd "%~dp0"
rd /s /q build
