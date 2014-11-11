#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char* input;
  char* exec;
  input = (char*)malloc(255*sizeof(char));

  //Reads in input, and parses it to the command
  fgets(input, sizeof(input), stdin);
  exec = strsep(&input, "\n");

  //Need to parse the rest of the string

  //Running the program
  execlp(exec, "-a", NULL);

  //Testing for execution of program
  printf("%s", exec);

  return 0;
}
