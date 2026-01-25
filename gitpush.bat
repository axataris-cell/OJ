@echo off
setlocal EnableDelayedExpansion

echo ============================
echo   Git Auto Push Script
echo ============================

REM Initialize git if needed
if not exist ".git" (
    git init
)

REM Get date & time via PowerShell (DD.MM.YYYY HH:MM)
for /f "delims=" %%I in (
  'powershell -NoProfile -Command "Get-Date -Format \"dd.MM.yyyy HH:mm\""' 
) do set DATE_TIME=%%I

REM Fallback if PowerShell failed
if "!DATE_TIME!"=="" (
    set DATE_TIME=%DATE% %TIME:~0,5%
)

REM Ask for optional commit message
set /p USER_MSG=Enter commit message (optional): 

REM Build commit message
if "!USER_MSG!"=="" (
    set COMMIT_MSG=!DATE_TIME!
) else (
    set COMMIT_MSG=!DATE_TIME! - !USER_MSG!
)

REM Add all files
git add -A

REM Commit (skip if nothing to commit)
git commit -m "!COMMIT_MSG!" || goto :end

REM Add remote if missing
git remote | find "origin" >nul
if errorlevel 1 (
    git remote add origin https://github.com/axataris-cell/OJ.git
)

REM Push
git push -u origin main

:end
echo ============================
echo   Push complete!
echo ============================
pause
