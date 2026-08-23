#include<windows.h>
#include<stdio.h>

char *get_path(char envName[]){
    // getting the temporary bytes to store in Memory
    // asking how many bytes are needed to store the Environment Variable
    DWORD charCount = GetEnvironmentVariableA(envName , NULL , 0);

    // if the charCount is 0, it means the Environment Variable does not exist or an error occurred
    if(charCount == 0){
        printf("It is fucked MANNN %lu\n " , GetLastError());
        return NULL;
    }
    // Allocation of the Memory on the basis of the
    char* buffer = (char*)malloc(charCount + 1);
    if(buffer == NULL){
        printf("Memory Allocation Failed");
        return NULL;
    }

    // Retrieving the Memory based on the memory located in the heap
    DWORD result = GetEnvironmentVariableA(envName , buffer , charCount + 1);
    
    if(result > 0){
        printf("PATH is Done\n");
        return buffer;
    }else
        printf("Failed to retrieve the Path: %lu\n" , GetLastError());
    
    free(buffer);
    return NULL;

}

int count_dir(char *path){
    int count = 0;
    for(int i = 0 ; path[i] != '\0'; i++){
        if (path[i] == ';')
            count++;
        

    }
    return count;

}

// TODO: works same as split(';')
char **parse_path(char *path){

    int count = count_dir(path);
    char **dir = malloc(count * sizeof(char*));

    int start = 0;
    int index = 0;

    for(int j = 0; path[j] != '\0'; j++){

        if (path[j] == ';' || path[j] == '\0'){
            int length = j - start;
            dir[index] = malloc((length+1) * sizeof(char));

            for(int k = start; k < j; k++){
                dir[index][k - start] = path[k];
            }

            dir[index][length] = '\0';

            index++;

            start = j + 1;

        }
    }

    return dir;
}
