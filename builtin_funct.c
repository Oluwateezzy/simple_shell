#include "main.h"
#include <string.h>

int (*built_in_func[6]) (char **) = {
	&tee_ch_dir,
	&tee_help_f,
	&tee_exit_f
};
static char *built_in_str[] = {
	"cd",
	"help",
	"exit"
};
/**
 * num_builtin - length of builtin function
 * Return: integer
 */
int num_builtin(void)
{

	return (sizeof(built_in_str) / sizeof(char *));
}

/**
 * tee_ch_dir - change directory builtin
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
 * tee_help_f - print help
 * @args: list of commands
 * Return: integer
 */
int tee_help_f(__attribute__((unused)) char **args)
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
 * tee_exit_f - exit function
 * @args: list of arguments
 * Return: integer
 */
int tee_exit_f(__attribute__((unused)) char **args)
{
	return (0);
}


static char *olds;

#undef strtok

#ifndef STRTOK
# define STRTOK strtok
#endif

/* Parse S into tokens separated by characters in DELIM.
   If S is NULL, the last string strtok() was called with is
   used.  For example:
    char s[] = "-abc-=-def";
    x = strtok(s, "-");     // x = "abc"
    x = strtok(NULL, "-=");     // x = "def"
    x = strtok(NULL, "=");      // x = NULL
        // s = "abc\0=-def\0"
*/
char *
STRTOK (char *s, const char *delim)
{
  char *token;

  if (s == NULL)
    s = olds;

  /* Scan leading delimiters.  */
  s += strspn (s, delim);
  if (*s == '\0')
    {
      olds = s;
      return NULL;
    }

  /* Find the end of the token.  */
  token = s;
  s = strpbrk (token, delim);
  if (s == NULL)
    /* This token finishes the string.  */
    olds = __rawmemchr (token, '\0');
  else
    {
      /* Terminate the token and make OLDS point past it.  */
      *s = '\0';
      olds = s + 1;
    }
  return token;
}
