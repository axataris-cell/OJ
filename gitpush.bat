@echo off
echo ============================
echo   Git Auto Push Script
echo ============================

if not exist ".git" (
    git init
)

REM Get date & time (YYYY-MM-DD HH:MM)
for /f "delims=" %%I in (
  'powershell -NoProfile -Command "Get-Date -Format ''yyyy-MM-dd HH:mm''"'
) do set DATE_TIME=%%I

REM Ask for commit message (optional)
set /p USER_MSG=Enter commit message (optional): 

REM Build commit message (NO delayed expansion)
if "%USER_MSG%"=="" (
    set COMMIT_MSG=%DATE_TIME%
) else (
    set COMMIT_MSG=%DATE_TIME% - %USER_MSG%
)

git add -A
git commit -m "%COMMIT_MSG%"

git remote | find "origin" >nul
if errorlevel 1 (
    git remote add origin https://github.com/axataris-cell/OJ.git
)

git push -u origin main

echo ============================
echo   Push complete!
echo ============================
pause
