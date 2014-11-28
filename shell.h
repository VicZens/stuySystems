#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>

char** parse_command(char* input);
int exec_command(char** args);
int check_command(char* input);
