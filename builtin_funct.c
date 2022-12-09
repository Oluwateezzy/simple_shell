#include "main.h"
int (*built_in_func[]) (char **) = {
	&tee_ch_dir,
	&tee_help_f,
	&tee_exit_f
};
/**
 * num_builtin - length of builtin function
 * Return: integer
 */
int num_builtin()
{
	return (sizeof(built_in_str) / sizeof(char *));
}

/**
 * ch_dir - change directory builtin
 * @args: list of commands
 * Return: integer
 */
int tee_ch_dir(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to cd \n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in cd");
		}
	}
	return (1);
}

/**
 * help_f - print help
 * @args: list of commands
 * Return: integer
 */
int tee_help_f(char **args)
{
	int i;
	printf("Oluwatobiloba & Valerie ALX group project\n");
	printf("Type program names and list of arguements, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < num_builtin(); i++)
	{
		printf("    %s\n", built_in_str[i]);
	}
	printf("use the man command for information on other programs.\n");
	return (1);
}

/**
 * exit_f - exit function
 * @args: list of arguments
 * Return: integer
 */
int tee_exit_f(char **args)
{
	return (0);
}
