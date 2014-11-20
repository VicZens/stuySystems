#include "shell.h"

//Every function requires a header
//-What it does
//-What the arguments are for
//-What the return value is for

int exec_command(char* run, char* arg) {
  int f, status;
  f = fork();
  
  if (f==0)
    execlp(run, " ", arg, NULL);
  else 
    wait(&status);

  return 0;
}

char** parse_command(char* input) {
  char** output;
  char* new_input;
  char* temp;
  output = (char**)malloc(256*sizeof(char));
  new_input = (char*)malloc(256*sizeof(char));
  temp = (char*)malloc(256*sizeof(char));
  
  new_input = strsep(&input, "\n");
  

  return output;
}

