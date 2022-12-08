#include "main.h"
/**
 * prompt - prompt and wait for the user to type a command
 * Return: void
 */
void prompt()
{
	char *line;
	char **args;
	int status;

	do
	{
		printf("valerie&tobi $ ");
		line = read_line();
		args = split_line(line);
		status = lsh_exec(args);

		free(line);
		free(args);
	} while(status);
}
