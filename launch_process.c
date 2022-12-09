#include "main.h"
/**
 * launch_process - start process and save the return value
 * @args: splited list of command
 * Return: integer
 */
int launch_process(char **args)
{
	pid_t pid, wait_pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("process");
	}
	else
	{
		do
		{
			wait_pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
