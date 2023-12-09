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

/**
 * struct path_l - struct for path linked list
 * @str: string
 * @next: next
*/

typedef struct path_l
{
	char *str;
	struct path_l *next;
} path_l;

int prompt_x(char **buffer);
char **get_command(char *buffer, char **av);
void exit_x(char *arg);
int file_missing_error(char *arg, char *exec_name);
int fork_exec(char **av, char **env, char *buffer);
void free_buffer_av(char *buffer, char **av);
int _getenv(char *var, char **env);

#endif /* SIMPLE_SHELL */
