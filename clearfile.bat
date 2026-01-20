@echo off

pushd "%~dp0"

for /r %%F in (*.exe) do (
    del /f /q "%%F"
)

for /r %%F in (*) do (
    if /i "%%~nxF"==".INP" del /f /q "%%F"
)

for /r %%F in (*) do (
    if /i "%%~nxF"==".OUT" del /f /q "%%F"
)

popd
echo Done.
