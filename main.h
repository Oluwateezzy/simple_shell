#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


void prompt(void);
char *read_line(void);
char **split_line(char *line);
int launch_process(char **args);
int (*built_in_func[]) (char**);
int tee_ch_dir(char **args);
int tee_help_f(char **args);
int tee_exit_f(char **args);
int num_builtin();
int execute(char **args);
int find_pipe(char *str, char **strpiped);

#endif
