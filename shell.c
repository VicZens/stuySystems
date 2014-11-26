#include "shell.h"

//Every function requires a header
//-What it does
//-What the arguments are for
//-What the return value is for

int exec_command(char** args) {
  int f, status;
  f = fork();
  
  if (f==0)
    execvp(args[0], args);
  else 
    wait(&status);

  return 0;
}

char** parse_command(char* input) {
  char** output;
  char* new_input;
  char* temp;
  output = (char**)malloc(16*sizeof(char));  
  new_input = (char*)malloc(256*sizeof(char));
  temp = (char*)malloc(256*sizeof(char));

  int i;
  
  printf("Before\n");
  printf("%s\n", input);
  while(input[i]) {
    printf("What?!");
    if(!strcmp(&input[i], "\n"))
      input[i] = '\0';
    printf("Value: %d\t Letter: %c", strcmp(&input[i], "\n"), input[i]);
    i++;
  }
  printf("After\n");
  i = 0;
  
  strcpy(new_input, input);
  printf("Copied - %s\n", new_input);
  
  if (strstr(new_input, " ")) {
    printf("Parsing 0\n");
    while(temp = strsep(&new_input, " ")) {
      printf("Parsing 1\n");
      output[i] = (char*)malloc(256*sizeof(char));
      strcpy(output[i], temp);
      printf("%s\n", output[i]);
      i++;
    }
  } else {
    output[0] = (char*)malloc(256*sizeof(char));
    strcpy(output[0], new_input);
  }
    
  return output;
}


