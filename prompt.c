#include "main.h"
/**
 * prompt - prompt and wait for the user to type a command
 * Return: void
 */
void prompt(void)
{
	char *line, *strpiped[2];
	char **args, **args2;
	int status;
	int pipe_flag = 0;

	do {
		printf(":)");
		line = read_line();
		pipe_flag = find_pipe(line, strpiped);
		if (pipe_flag == 0)
		{
			args = split_line(line);
			status = execute(args);
		}
		if (pipe_flag == 1)
		{
			args = split_line(strpiped[0]);
			status = execute(args);
			args2 = split_line(strpiped[1]);
			status = execute(args2);
			free(args2);
		}
		free(line);
		free(args);
	} while (status);
}
