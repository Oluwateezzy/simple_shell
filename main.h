#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFFER_TOKEN 64
#define BUFFER_DELIMITER " \t\r\n\a"
#define MAX_SIZE 1024

char *built_in_str[] = {
	"cd",
	"help",
	"exit"
};

void prompt(void);
char *read_line(void);
char **split_line(char *line);
int launch_process(char **args);
int tee_ch_dir(char **args);
int tee_help_f(char **args);
int tee_exit_f(char **args);
int num_builtin();
int execute(char **args);
int (*built_in_func[])(char **);

#endif
