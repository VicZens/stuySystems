#include "shell.h"

char** parse_command(char* input) {
  char** output;
  char* new_input;
  char* temp;
  output = (char**)malloc(16*sizeof(char));  
  new_input = (char*)malloc(256*sizeof(char));
  temp = (char*)malloc(256*sizeof(char));

  int i = 0;
  
  while(input[i]) {
    if(!strcmp(&input[i], "\n"))
      input[i] = '\0';
    i++;
  }
  
  i = 0;
  strcpy(new_input, input);

  if (strstr(new_input, " ")) {
    while(temp = strsep(&new_input, " ")) {
      output[i] = (char*)malloc(256*sizeof(char));
      strcpy(output[i], temp);
      i++;
    }
  } else {
    output[0] = (char*)malloc(256*sizeof(char));
    strcpy(output[0], new_input);
  }
  
  return output;
}

int exec_command(char** args) {
  int f, status;
  f = fork();
  
  if (f==0)
    execvp(args[0], args);
  else 
    wait(&status);

  return 0;
}

int check_command(char* input) {
  int ret_val = 0;
  char** cmd;
  if(strstr(input, "cd")) {
    cmd = parse_command(input);
    chdir(cmd[1]);
  } else if (strstr(input, "exit")) {
    printf("Goodbye...\n");
    sleep(1);
    exit(0);
  }
  return ret_val;
}
