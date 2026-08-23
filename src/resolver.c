#include<stdio.h>
#include<stdlib.h>
#include "side_chick.h"
#include<string.h>
#include<windows.h>

/*
TODO: searches the executable files in the PATH
*/

/*
first of all , we will get the command and also get the PATH variable from the evn variables and will format it into executable paths.
*/

char* resolve_path(char *command){
    char *path = get_path("PATH");
    char **dirs = parse_path(path);
    int num_dir = count_dir(path);

    for(int i = 0; i< num_dir; i++){
        // "c:/system32" + '/' + 'notepad' + '.exe' + '/0'
        int length = strlen(dirs[i]) + 1 + strlen(command) + 4 + 1;

        // allocating the memory 
        char* candidate = malloc(length);

        sprintf(
            candidate,
            "%s\\%s.exe",
            dirs[i],
            command
        );
        // checks whether the file points to folder or a file
        DWORD attribute = GetFileAttributesA(candidate);
        
        // if the file is not INVALID
        if (attribute != INVALID_FILE_ATTRIBUTES){

            // freeing the memory for the ownership
            for (int j = 0; j < num_dir; j++)
                free(dirs[j]);

            free(dirs);
            free(path);

            return candidate;
        }

        printf("Trying: %s\n", candidate);

        free(candidate);
    }

    // releasing the memory in the case of the 'NULL' return case
    for(int i = 0; i < num_dir; i++)
        free(dirs[i]);

    free(dirs);
    free(path);

    return NULL;
}