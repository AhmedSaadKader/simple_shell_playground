#include "main.h"

/**
 * path_linked - creates a linked list from path
 *
 * Return: int
*/

int path_linked(void)
{
	path_l *path_head = NULL, *path_node;
	int i = 0;
	char *path, *token;

	path = getenv("PATH");

	token = strtok(path, ":");

	while (token != NULL)
	{
		path_node = malloc(sizeof(path_l));
		path_node->str = strdup(token);
		path_node->next = path_head;
		path_head = path_node;
		token = strtok(NULL, ":");
	}

	path_node = path_head;
	while (path_node != NULL)
	{
		printf("%s\n", path_node->str);
		path_node = path_node->next;
	}

	while (path_head != NULL)
	{
		path_node = path_head;
		path_head = path_head->next;
		free(path_node->str);
		free(path_node);
	}
}
