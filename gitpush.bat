@echo off
setlocal

echo ============================
echo   Git Auto Push Script
echo ============================

REM Initialize git if needed
if not exist ".git" (
    git init
)

REM Get date & time via PowerShell
for /f "delims=" %%I in (
  'powershell -NoProfile -Command "Get-Date -Format \"dd:MM:yyyy HH:mm\""' 
) do set COMMIT_MSG=%%I

REM Fallback if PowerShell failed (very important)
if "%COMMIT_MSG%"=="" (
    set COMMIT_MSG=%DATE% %TIME:~0,5%
)

REM Add all files
git add -A

REM Commit (force non-empty message)
git commit -m "%COMMIT_MSG%" || goto :end

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
