#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main() {
  char curr_path[255];
  getcwd(curr_path, sizeof(curr_path));
  printf("Current Working Directory: %s \n", curr_path);

  DIR *d;
  d = opendir(curr_path);

  struct dirent* entry;
  printf("Directories:\n");
  while (entry = readdir(d)) {
    if (entry->d_type==4) {
      printf("\t %s \n", entry->d_name);
    }
  }

  printf("\n");
  rewinddir(d);

  int size;
  struct stat for_size;
  stat(curr_path, &for_size);
  printf("Regular Files:\n");
  while (entry = readdir(d)) {
    if (entry->d_type==8) {
      size = size + for_size.st_size;
      printf("\t %s \n", entry->d_name);
    }
  }
  printf("Size: %d\n", size);

  closedir(d);
  
  return 0;
}
