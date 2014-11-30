#include "shell.h"

char** parse_command(char* input) {
  char** output;
  char* new_input;
  char* temp;
  output = (char**)malloc(16*sizeof(char));  
  new_input = (char*)malloc(256*sizeof(char));
  temp = (char*)malloc(256*sizeof(char));

  int i = 0;
  input = remove_newline(input);
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
  i = 0;
  
  return output;
}

int exec_command(char** args) {
  int f, status;
  f = fork();

  if (f==0)
    execvp(args[0], args);
  else 
    wait(&status);

  return status;
}

int check_and_run(char* input) {
  char** cmd;
  
  if(!check_command(input)) {
    cmd = parse_command(input);
    exec_command(cmd);
  }
  return 0;
}

int redirect(char* source, char* dest) {
  int fd_source, fd_dest;
  char temp[256] = "touch ";
  strcat(temp, dest);
  check_and_run(temp);
  fd_dest = open(dest, O_WRONLY | O_TRUNC);
  fd_source = dup(STDOUT_FILENO);
  dup2(fd_dest, STDOUT_FILENO);
  check_and_run(source);
  dup2(fd_source, STDOUT_FILENO);

  return 0;
}

char* remove_newline(char* input) {
  int i = 0;

  while(input[i]) {
    if(!strcmp(&input[i], "\n"))
      input[i] = '\0';
    i++;
  }

  return input;
}

int check_command(char* input) {
  int ret_val = 0;
  char** cmd;
  char* temp;
  
  if (!strcmp(input, "\n")) {
    ret_val++;
  } else if (strstr(input, ";")) {
    temp = strsep(&input, ";");
    check_and_run(temp);
    check_and_run(input);
    ret_val++;
  } else if(strstr(input, "cd")) {
    cmd = parse_command(input);
    chdir(cmd[1]);
    opendir(cmd[1]);
    ret_val++;
  } else if(strstr(input, ">")) {
    temp = strsep(&input, ">");
    input = remove_newline(input);
    redirect(temp, input);
    ret_val++;
  } else if(strstr(input, "<")) {
    temp = strsep(&input, "<");
    input = remove_newline(input);
    redirect(input, temp);
    ret_val++;
  } 
  /*
    else if(strstr(input, "|")) {
    temp = strsep(&input, "|");
    input = remove_newline(input);
    piping(temp, input);
    ret_val++;
    } 
    else if(strstr(input, ">>")) {
    printf("Found it");
    temp = strsep(&input, ">>");
    input = remove_newline(input);
    redirect_append(temp, input);
    ret_val++;
    } else if(strstr(input, "<<")) {
    temp = strsep(&input, "<<");
    input = remove_newline(input);
    redirect_append(input, temp);
    ret_val++;
    }
  */

  return ret_val;
}

/*
  int redirect_append(char* source, char* dest) {
  int fd_source, fd_dest;
  //char temp[256] = "touch ";
  //strcat(temp, dest);
  //check_and_run(temp);
  fd_dest = open(dest, O_WRONLY | O_APPEND);
  fd_source = dup(STDOUT_FILENO);
  dup2(fd_dest, STDOUT_FILENO);
  check_and_run(source);
  dup2(fd_source, STDOUT_FILENO);

  return 0;
  }
*/

/*
  int piping(char* source, char* dest) {
  
  char string[SIZE];
  freopen("/dev/null", "a", stdout);
  setbuf(stdout, string);

  return 0;
  }
*/
