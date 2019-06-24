@echo off

where cmake 1>nul 2>nul
if %ERRORLEVEL% EQU 1 (
    echo "You need to install cmake."
    goto :eof
)

if not exist cmake_build (
    mkdir cmake_build
)

cd cmake_build
cmake ..\src
cmake --build .
cd ..