#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1024
int main(){
    char* command = malloc(LEN);
    fgets(command , LEN , stdin);
    if (fgets(command, LEN, stdin) != NULL) {
        
        // FIX: Compare the first character directly to the newline character
        if (command[0] == '\0') { 
            printf("string is empty\n");
        } else {
            printf("You entered: %s", command);
        }
    }
    printf("\n%s" , command);

    free(command);
    return 0;
}