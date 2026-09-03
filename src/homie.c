#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include "baddie.h"

bool is_builtin(char *command){

    if (strcmp(command , "gyatt") == 0)
        return true;

    else if (strcmp(command , "whereami") == 0)
        return true;

    else if (strcmp(command , "ls") ==0)
        return true;

    else if (strcmp(command , "cooked") == 0)
        return true;
    
    else if (strcmp(command , "mog") == 0)
        return true;

    else if (strcmp(command , "vibe") == 0)
        return true;

    else if (strcmp(command , "about") == 0)
        return true;
    
    else if (strcmp(command , "skedaddle") == 0)
        return true;

    else if (strcmp(command , "exit") == 0)
        return true;
    
    else if (strcmp(command , "kill") == 0)
        return true;

    else
        return false;
    
}

void execute_builtin(char *command){
    char **args = parse_args(command);
    if (strcmp(args[0] , "vibe") == 0)
        printf("\n$brainrot:/> NIGGA v1.0");

    else if (strcasecmp(args[0] , "whereami") == 0){
        // printf("whereami is called");
        TCHAR currentDir[MAX_PATH];

    // Fetch the current directory
        DWORD result = GetCurrentDirectory(MAX_PATH, currentDir);

    if (result == 0) {
        printf("Failed to get current directory. Error code: %lu\n", GetLastError());
        
    } else if (result > MAX_PATH) {
        printf("Buffer too small. Required size: %lu characters.\n", result);
        
    }

    // Print the directory path
    // Note: %s works if your project uses ANSI characters. 
    // If your project uses UNICODE, use wprintf(L"Current Directory: %s\n", currentDir);
    printf("\nCurrent Directory: %s", currentDir);
    }
}
