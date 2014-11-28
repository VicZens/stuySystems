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

int check_command(char* input) {
  int ret_val = 0;
  char** cmd;
  char* temp;

  if(strstr(input, "cd")) {
    cmd = parse_command(input);
    chdir(cmd[1]);
    opendir(cmd[1]);
    ret_val++;
  } else if (!strcmp(input, "\n")) {
    ret_val++;
  } else if (strstr(input, "exit")) {
    printf("Goodbye...\n");
    //sleep(1);
    exit(0);
  } else if (strstr(input, ";")) {
    temp = strsep(&input, ";");
    parse_command(temp);
    check_and_run(temp);

    parse_command(input);
    check_and_run(input);
    ret_val++;
  }

  return ret_val;
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

int check_and_run(char* input) {
  char** cmd;
  
  if(!check_command(input)) {
    cmd = parse_command(input);
    exec_command(cmd);
  }
  return 0;
}
