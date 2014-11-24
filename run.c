#include "shell.h"

//Testing Time!!!
int main() {
  char* input = (char*)malloc(256*sizeof(char));
  char** clear = parse_command("clear");
  printf("Please Initiate (Type in Initiate, CasE-SenSitivE)\n");
  fgets(input, sizeof(input), stdin);
  exec_command(clear);

  // while(input) {  }

  return 0;
}
