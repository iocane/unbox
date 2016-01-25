@echo off
set release=%1
set arch=%2
set email=%3
set platform=%4
for /f "usebackq tokens=*" %%a in (`git describe`) do set version=%%a
for /f "usebackq tokens=*" %%a in (`git show --quiet --format^=format:%%cd --date^=short`) do set date=%%a
for /f "usebackq tokens=*" %%a in (`git rev-parse --abbrev-ref HEAD`) do set branch=%%a
echo #define JVERSION "%release%/%arch%/%platform%/%branch%/unbox-%version%/%email%/%date% 00:00:00"

