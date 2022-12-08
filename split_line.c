#include "main.h"
/**
 * split_line - split line into tokens
 * @line: line to be splitted
 * Return: char **
 */
char **split_line(char *line)
{
	int bufsize = 64;
	char **tokens = malloc(sizeof(char*) * bufsize);
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
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (token == NULL)
			{
				fprintf(stderr, "memory allocation error in split_line function\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL)
