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
  output = (char**)malloc(256*sizeof(char));
  char* new_input;
  new_input = (char*)malloc(256*sizeof(char));
  char* temp;
  temp = (char*)malloc(256*sizeof(char));
  int i;
  
  new_input = strsep(&input, "\n");
  printf("%s\n", new_input);

  printf("1\n");
  while(new_input) {
    printf("2\n");
    strsep(&new_input, " ");
    printf("3\n");
    strcpy(output[i], temp);
    i++;
  }
  
  i = 0;
  //while(output[i]) {
  //strcpy(output[0], "Hello");
  //printf("%s\n", output[0]);
  //i++; }
  return output;
}

