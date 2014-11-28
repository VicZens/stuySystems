#include "shell.h"

//Testing Time!!!
int main() {
  char curr_dir[256];
  char* input = (char*)malloc(256*sizeof(char));
  char** cmd = parse_command("clear");
  printf("Initiating...\n");
  sleep(1.5);
  exec_command(cmd);
  printf("Welcome to Bash! \n(Please seperate all your arguments with a space, aside from when you use ;)\n\n");
  
  while(input) {
    getcwd(curr_dir, sizeof(curr_dir));
    printf("%s - %d - Bash: ", curr_dir, getpid());
    fgets(input, sizeof(input), stdin);
    check_and_run(input);
  }

  return 0;
}
