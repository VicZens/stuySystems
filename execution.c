#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char exe[255];
  fgets(exe, sizeof(exe), stdin);

  printf("%s", exe);

  return 0;
}
