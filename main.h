#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int prompt_x(char **buffer);
char **get_command(char *buffer, char **av);
void exit_x(char *arg);
int file_missing_error(char *arg, char *exec_name);
int fork_exec(char **av, char **env, char *buffer);
void free_buffer_av(char *buffer, char **av);

#endif /* SIMPLE_SHELL */
