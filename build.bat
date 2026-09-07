@echo off
setlocal

echo [BRAINROT BUILD] Compiling Brainrot Shell (67 Edition)...

if not exist bin (
    mkdir bin
)

gcc -Wall -Wextra src/baddie.c src/homie.c src/resolver.c src/side_chick.c src/main.c -o bin/brainrot.exe

if %ERRORLEVEL% EQU 0 (
    echo [BRAINROT BUILD] SUCCESS: Binary compiled to bin\brainrot.exe
    echo [BRAINROT BUILD] Run with: .\bin\brainrot.exe
) else (
    echo [BRAINROT BUILD] ERROR: Compilation failed with exit code %ERRORLEVEL%
)

endlocal
