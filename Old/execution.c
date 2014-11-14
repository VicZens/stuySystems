#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char* input;
  char* exec;
  char* arg;

  input = (char*)malloc(255*sizeof(char));
  exec = (char*)malloc(255*sizeof(char));
  arg = (char*)malloc(255*sizeof(char));

  //Reads in input, and parses it to the command
  fgets(input, sizeof(input), stdin);
  arg = strsep(&input, "\n");
  exec = strsep(&arg, " ");

  //Running the program
  execlp(exec, " ", arg, NULL);
  
  //^^^ I don't get why, but once the " " is taken out, it doesn't work as
  //intended. Since this works, which was achieved through random testing,
  //I'm going to leave it be.

  //Testing for execution of program
  printf("%s", exec);
  printf("%s", arg);

  return 0;
}
