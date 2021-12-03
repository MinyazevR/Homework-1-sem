@echo off
for /d %%b in (.\*) do (cd %%b
for /d %%b in (.\*) do (cd %%b
msbuild -m
cd../)
cd../)
for /r %~dp0 %%k in (*.exe) do (echo %%k & %%k 2
if not errorlevel 0 (
echo Test failed
) else (
echo Tests passed successfully
)
)
cd %~dp0