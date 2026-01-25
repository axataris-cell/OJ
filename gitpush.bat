@echo off
echo ============================
echo   Git Auto Push Script
echo ============================

REM Initialize git (only if not already a repo)
if not exist ".git" (
    git init
)

REM Get date & time
for /f "delims=" %%I in (
  'powershell -NoProfile -Command "Get-Date -Format ''yyyy-MM-dd HH:mm''"'
) do set DATE_TIME=%%I

REM Ask for commit message (optional)
set /p USER_MSG=Enter commit message (optional): 

REM Build final commit message
if "%USER_MSG%"=="" (
    set COMMIT_MSG=%DATE_TIME%
) else (
    set COMMIT_MSG=%DATE_TIME% - %USER_MSG%
)


REM Add all files
git add -A

REM Commit
git commit -m "%COMMIT_MSG%"

REM Add remote only if not already added
git remote | find "origin" >nul
if %errorlevel% neq 0 (
    git remote add origin https://github.com/axataris-cell/OJ.git
)

REM Push to main branch
git push -u origin main

echo ============================
echo   Push complete!
echo ============================
pause
