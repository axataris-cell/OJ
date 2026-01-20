@echo off
echo ============================
echo   Git Auto Push Script
echo ============================

REM Initialize git (only if not already a repo)
if not exist ".git" (
    git init
)

REM Ask for commit message
set /p COMMIT_MSG=Enter a fancy commit message: 

REM If empty, cancel
if "%COMMIT_MSG%"=="" (
    echo Commit message cannot be empty!
    pause
    exit /b
)

REM Add all files
git add -A

REM Commit with user message
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
