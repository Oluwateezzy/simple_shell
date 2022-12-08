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

void prompt(void);
char *read_line(void);
char **split_line(char *line);

#endif
