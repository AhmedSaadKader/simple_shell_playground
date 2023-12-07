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


void print_arg(char **args);
int prompt_x(char **buffer);
char **tokenize_string(char *buffer, char *filename, char **av);

#endif /* SIMPLE_SHELL */
