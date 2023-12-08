#include "main.h"

/**
 * exit_x - exits the shell
 * @arg: exit argument
*/

void exit_x(char *arg)
{
	if (strcmp(arg, "exit") == 0)
		exit(EXIT_SUCCESS);
}
