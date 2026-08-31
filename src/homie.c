#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

void execute_builtin(char *agrs){
    if (strcmp(agrs , "about") == 0)
        printf("\n$brainrot:/> NIGGA v1.0");
}
