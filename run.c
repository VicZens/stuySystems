#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>

#include "shell.h"

//Testing Time!!!
int main() {
  char* input;
  input = (char*)malloc(256*sizeof(char));

  printf("Please input: ");
  fgets(input, sizeof(input), stdin);
  input = strsep(&input, "\n");

  exec_command(input, "Hi");

  return 0;
}
