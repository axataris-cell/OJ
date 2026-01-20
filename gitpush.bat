@echo off
echo ============================
echo   Git Auto Push Script
echo ============================

REM Initialize git (only if not already a repo)
if not exist ".git" (
    git init
)

REM Add all files
git add .

REM Commit with default message
git commit -m "Axataris's Code"

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