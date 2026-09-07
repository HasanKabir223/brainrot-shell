## Process and Threads  

Basically , Process is the container but the thread is the thing  that executes the program.  
While creating the process , we are also provided the thread. Also a single process gets many threads.
  
So the Process is the House and Threads are the Persons working in the House.  

## Overview of Each file

Main.c  -  Contains the main loop and the logic behind the brain rot shell. 

side_chick.c - contains the supporting methods for the resolver.h  
-> char *get_path(char envName[]);  
-> int count_dir(char *path);  
-> char **parse_path(char *path); = splits the path with seperators = ';'

resolver.c - searches the executable files into the ev varibale called "PATH".  
-> char* resolve_path(char *command);

baddie.c - mainly has the methods to parse the arguments  
-> int count_args(char* command);   
-> char** parse_args(char* command); = passes the command to args to differentiate it btw the built-in and the external programs.

 
# Cheat for any program for C.
lets say we have a command: 

1.) calculate how much memory to rent in the heap for this specific command. 
 
2.) now malloc() that much memory to the heap. 

3.) use that allocated memory to store the results. 

4.) free that allocated memory.


