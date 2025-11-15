@echo off
setlocal

REM Get folder where this bat file is located
set "base=%~dp0"

set "dir1=%base%OnlineJudge"
set "dir2=%base%ProgrammingTips"

echo Base directory: %base%
echo Searching for subfolders...

if exist "%dir1%" (
    echo Deleting .exe files in: %dir1%
    del "%dir1%\*.exe" /s /q
) else (
    echo Subfolder not found: %dir1%
)

if exist "%dir2%" (
    echo Deleting .exe files in: %dir2%
    del "%dir2%\*.exe" /s /q
) else (
    echo Subfolder not found: %dir2%
)

echo Done.
pause
