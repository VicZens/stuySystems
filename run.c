#include "shell.h"

//Testing Time!!!
int main() {
  char* input = (char*)malloc(256*sizeof(char));
  char** cmd;// = parse_command("clear");
  printf("Please Initiate...\n");
  //fgets(input, sizeof(input), stdin);
  //exec_command(cmd);

  while(input) {
    printf("Bash: ");
    fgets(input, sizeof(input), stdin);
    cmd = parse_command(input);
    exec_command(cmd);
  }

  return 0;
}
