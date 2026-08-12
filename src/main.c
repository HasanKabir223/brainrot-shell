#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

bool is_background(char *command)
{
    size_t len = strlen(command);

    if (len > 0 && command[len - 1] == '&')
        return true;

    return false;
}


#define LEN 1024



int main(){
    char* command = malloc(LEN);

    while (1){
        printf("brainrot> ");
        // stdin -> takes the input from the user
        fgets(command , LEN , stdin); // taking  the input from user 

        // TODO: ['e' , 'x' , 'i' , 't' , '\n' , '\0'] to ['e' , 'x' , 'i' , 't' , '\0']
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n'){
            command[len-1] = '\0';
        }

        bool check_bg = is_background(command);

        if (check_bg){
            printf("\nusing the external program as foreground function\n\n");
            command[len - 2] = '\0';
        }

        // exiting the loop
        if(strcmp(command , "exit") == 0)
            exit(0);
    }
    
    return 0;
}

