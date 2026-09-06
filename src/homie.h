#ifndef HOMIE_H
#define HOMIE_H

bool is_builtin(char *command);
void execute_builtin(char *command);
char* get_current_dir();

#endif