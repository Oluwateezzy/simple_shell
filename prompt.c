#include "main.h"
/**
 * prompt - prompt and wait for the user to type a command
 * Return: void
 */
void prompt()
{
	char *line, *parsedArgs[100], *parsed_piped[1000];
	char **args;
	int status;
	int exec_flag = 0;

	do
	{
		printf("valerie&tobi $ ");
		line = read_line();
		exec_flag = process_string(#line, parsedArgs, parsed_piped);
		if (exec_flag == 1)
		{
			args = split_line(line);
			status = execute(args);
		}

		free(line);
		free(args);
	} while(status);
}
