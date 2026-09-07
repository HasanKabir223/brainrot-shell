#include <stdio.h>
#include "C:\Users\Hasan\Projects\shell\brainrot-shell\src\baddie.h"
#include "C:\Users\Hasan\Projects\shell\brainrot-shell\src\homie.h"
#include <stdlib.h>
#include<windows.h>
#include <string.h>
#define LEN 1024


int main(){

    char* command = malloc(LEN);
    fgets(command , LEN , stdin);

    char** args = parse_args(command);
    printf("number of arguments are: %d\n" , count_args(command));
    int n = strlen(command) -1;

    while (n >= 2 && command[n] != '\\') {
    command[n] = '\0';
    n--;

    if (command[n] == '\\')
        break;
}

// Optional: remove the backslash itself if desired
if (n >= 0 && command[n] == '\\') {
    command[n] = '\0';
}

if (SetCurrentDirectory(command)) 
        printf("\nCurrent Directory: %s"  , get_current_dir());
    else 
        printf("\nFailed to change directory. Error code: %lu\n", GetLastError());

    printf("\nafter the transform: %s" , command);

    
    free(command);
    return 0;
    

}