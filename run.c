#include "shell.h"

//Testing Time!!!
int main() {
  char curr_dir[256];
  char* input = (char*)malloc(256*sizeof(char));
  char** cmd = parse_command("clear");
  printf("Initiating...\n");
  sleep(1.5);
  exec_command(cmd);
  printf("Welcome to Bash! (Please remember to seperate all your arguments with a space)\n");
  
  while(input) {
    getcwd(curr_dir, sizeof(curr_dir));
    printf("%s - Bash: ", curr_dir);
    fgets(input, sizeof(input), stdin);
    if(!check_command(input)) {
      cmd = parse_command(input);
      exec_command(cmd);
    }
  }

  return 0;
}
