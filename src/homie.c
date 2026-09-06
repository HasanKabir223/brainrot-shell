#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include "baddie.h"

char* get_current_dir(){
    // asking the os to get the size of the command , and then store it in the heap memory
    DWORD required_size = GetCurrentDirectory(0 , NULL);
    if (required_size == 0){
        printf("\nFailed to get the Determined path , Error: %lu" , GetLastError());
        return NULL;
    }

    // ask the heap memory to rent on the basis of the memory required
    char* buffer = (char*)malloc(required_size * sizeof(char));
    if (buffer == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // now filling out that buffer for execution.
    DWORD result = GetCurrentDirectory(required_size , buffer);
    if (result == 0){
        printf("Failed to get the path of the current directory , Error: %lu" , GetLastError());
        free(buffer);
        return NULL;
    }

    return buffer;
}

bool is_builtin(char *command){

    if (strcasecmp(command , "gyatt") == 0 || strcasecmp(command , "&gyatt") ==0 || strcasecmp(command , "gyatt..") == 0)
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

    
    return false;
    
}

void execute_builtin(char *command){
    char **args = parse_args(command);
    int num_args = count_args(command);

    // to get the version of the current shell
    if (strcmp(args[0] , "vibe") == 0 && num_args==1)
        printf("\n$brainrot:/> NIGGA v1.0");

    // to get the location of the current dir.
    if (strcasecmp(args[0] , "whereami") == 0){
        // getting the path of the current dir
        char* path  = get_current_dir();
        printf("\nCurrent dir: %s" , path);
        free(path);
    }

    // to navigate through the files.
    // gyatt is same as "cd"
    // gyatt has 3 version.
    if (strcasecmp(args[0] , "gyatt") == 0){
        char* curr_dir = get_current_dir();
        
        // adding the strings
        // "c:\User" + "\\" + "Desktop"
        strcat(curr_dir , "\\");
        strcat(curr_dir , args[1]);
    
        // using the SetCurrentDirectory for navigation
    if (SetCurrentDirectory(curr_dir)) {
        printf("\nCurrent Directory: %s"  , curr_dir);
    } else {
        printf("\ncurr dir: %s" , curr_dir);
        printf("\ncommand %s is not located" , command);
        printf("\nFailed to change directory. Error code: %lu", GetLastError());
    }
    // freeing up the heap memory to prevent the memory leak.
    free(curr_dir);
    }

    // TODO: for the navigation across the Whole system(global variable)
    if (strcasecmp(args[0] , "&gyatt") == 0 && num_args==2){
        if (SetCurrentDirectory(args[1])) 
        printf("\nCurrent Directory: %s"  , args[1]);
    else 
        printf("\nFailed to change directory. Error code: %lu\n", GetLastError());
    
    }

    if (strcasecmp(args[0] , "gyatt..") == 0){
        char* curr_dir = get_current_dir();
        int n = strlen(curr_dir) - 1;

        // "C:/User/Docs" -> "C:/User/"
        // removing the char until it's "\"
        while (curr_dir[n] != '\\'){
            curr_dir[n]='\0';
            n--;
            
            // breaking or else "c:" will be remained
            if (curr_dir[n] == '\\')    break;
        }

        // "c:/Users/" -> "C:/Users"
        // strlen(curr_dir) > 3 - to get the access of the root drive. "c:" and the "c:\" are two complete different thing
        // we need "c:\" to access the root c drive
        if (curr_dir[n] == '\\' && strlen(curr_dir) > 3) curr_dir[n] = '\0';
        
        if (SetCurrentDirectory(curr_dir)){
        char* path = get_current_dir();
        printf("\nCurrent Directory: %s" , path);
        free(path);
        }else 
        printf("\nFailed to change directory. Error code: %lu\n", GetLastError());

        free(curr_dir);
    }
    

    free(args);
}
