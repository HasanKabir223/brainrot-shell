#ifndef SIDE_CHICK_H
#define SIDE_CHICK_H

char *get_path(char envName[]);
int count_dir(char *path);
char **parse_path(char *path);

#endif