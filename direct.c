#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main() {
  char curr_path[255];
  getcwd(curr_path, sizeof(curr_path));
  printf("Current Working Directory: %s \n", curr_path);

  //while (entry = readdir(d)) {  
  //}

  return 0;
}
