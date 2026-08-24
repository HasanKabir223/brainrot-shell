#include <stdio.h>
#include <stdlib.h>

// TODO: count the number of words
int count_args(char *command){
    int count = 0;
    int char_count = 0;

    for (int i = 1; command[i] != '\0'; i++){
        if (command[i] != ' ' && command[i-1] == ' ') count++;

        if (command[i] != ' ') char_count++;
    }

    if (char_count == 0 || command[0] == '\0') return 0;

    if (command[0] == ' ')
        return count;
    else
        return count + 1;
}

char **parse_args(char *command){

    int args_num = count_args(command);
    char** output = malloc((args_num+1) *sizeof(char*));

    if (output == NULL) return NULL;

    int index = 0;
    int start = 0;

    for (int i = 0; ; i++){
        
        if (command[i] == ' ' || command[i] == '\0'){

            // was there any word before.
            if (i > start){
                int length = i - start;

                //  allocating the memory for this arguments
                output[index] = malloc((length + 1) * sizeof(char));
                
                // output is NULL
                if (output[index] == NULL){
                    // cleaning up the shit if the arguments is NULL
                    for (int j = 0; j < index; j++)
                        free(output[j]);

                    free(output);
                    return NULL;
                }

                // copy the word
                for (int k = 0; k < i; k++){
                    output[index][k - start] = command[k];
                }

                output[index][length] = '\0';
                index++;
            }

            // if we have reached to the last element
            if (command[i] == '\0') break;

            start = i + 1;
        }
    }
    output[index] = NULL;
    return output;
}


int main(){
    
    char *command = "hello          world";
    int count = count_args(command);
    char **output = parse_args(command);
    printf("number of args is: %d\n" , count);
    printf("printing the output\n");

    for (int i = 0; output[i] != NULL; i++)
    {
        printf("argv[%d] = %s\n", i, output[i]);
    }

    for (int i = 0; output[i] != NULL; i++)
    {
        free(output[i]);
    }

    free(output);

    return 0;
}