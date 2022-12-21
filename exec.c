#include "main.h"
/**
 * execute - execute process
 * @args: list of command
 * Return: integer
 */
int execute(char **args)
{
	int i;
	char *built_in_str[] = {
		"cd",
		"help",
		"exit"
	};

	if (args[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i  < num_builtin(); i++)
	{
		if (strcmp(args[0], built_in_str[i]) == 0)
		{
			return ((*built_in_func[i])(args));
		}
	}
	return (launch_process(args));
}
