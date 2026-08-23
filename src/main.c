#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<windows.h>
#include "resolver.h"
#include "side_chick.h"

bool is_background(char *command){
    // background process contains the '&'
    size_t len = strlen(command);

    if (len > 0 && command[len - 1] == '&')
        return true;

    return false;
}

void execute_external(char* command , bool is_bg){
    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {0};

    si.cb = sizeof(si);
    // size_t len = strlen(command);

    BOOL success = CreateProcessA(
        NULL,
        command,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );

    if(!success){
        printf("$brainrot: failed to create the Process, Error: %lu\n" , GetLastError());
        return;
    }

    if (!is_bg)
    {
        WaitForSingleObject(pi.hProcess, INFINITE);
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

#define LEN 1024

int main(){
    char* command = malloc(LEN);

    while (1){
        printf("$brainrot:/> ");
        // stdin -> takes the input from the user
        fgets(command , LEN , stdin); // taking  the input from user 

        // TODO: ['e' , 'x' , 'i' , 't' , '\n' , '\0'] to ['e' , 'x' , 'i' , 't' , '\0']
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n'){
            command[len-1] = '\0';
        }

        bool check_bg = is_background(command);
        
        if (check_bg){
            if (len >= 2 && command[len - 2] == ' ')
                command[len - 2] = '\0';
            else
                command[len - 2] = '\0';
        }
        // exiting the loop
        if(strcmp(command , "exit") == 0)
            exit(0);

        
        char* resolved_command = resolve_path(command);

        if(resolved_command != NULL){
            execute_external(command, check_bg);

            free(resolved_command);
        }else
            printf("brainrot: command not found: %s\n" , command);



        // execute_external(command , check_bg);

        
    }
    
    return 0;
}

