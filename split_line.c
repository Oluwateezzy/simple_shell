#include "main.h"
#define BUFFER_DELIMITER " \t\r\n\a"
/**
 * split_line - split line into tokens
 * @line: line to be splitted
 * Return: char **
 */
char **split_line(char *line)
{
	int bufsize = 64;
	char **tokens = malloc(sizeof(char *) * bufsize);
	char *token;
	int position = 0;

	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error in split_line function\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, BUFFER_DELIMITER);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, (bufsize * sizeof(char *)));
			if (token == NULL)
			{
				fprintf(stderr, "memory allocation error in split_line function\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, BUFFER_DELIMITER);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * find_pipe - check and modify piped string
 * @str: list of command
 * @strpiped: storage parameter for piped
 * Return: integer
 */
int find_pipe(char *str, char **strpiped)
{
	int i;

	for (i = 0; i < 2; i++)
	{
		strpiped[i] = strsep(&str, "|");
		if (strpiped[i] == NULL)
			break;
	}
	if (strpiped[1] == NULL)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
