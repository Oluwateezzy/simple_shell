#include "main.h"
/**
 * read_line2 - read line from standard input
 * Return: char
 */
char *read_line2(void)
{
	int bufsize = 1024;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int ch;

	if (!buffer)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		ch = getchar();

		if (ch == EOF || ch == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = ch;
		}
		position++;

		/* if line is more than 1024 then reallocate memory */
		if (position >= bufsize)
		{
			bufsize += 1024;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
