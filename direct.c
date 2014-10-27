#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>


int main() {
  char current_directory[700];

  char* files[700];
  int* sizes[sizeof(int)];

  DIR* curr_dir;
  struct dirent* file;

  getcwd(current_directory, sizeof(current_directory));

  printf("Directories");
  while (file = readdir(current_directory)) {
    if (file->d_type==4)
      printf("\t %s \n", file->d_name);
  }
  

  closedir(curr_dir);
  return 0;
}


/*
  int main(char path[255]) {
  char curr_path[255];
  //
  DIR* d;
  struct dirent* entry;
  //
  int size;
  struct stat for_size;

  //Current Directory
  getcwd(curr_path, sizeof(curr_path));
  printf("Current Working Directory: %s \n", curr_path);

  //Getting the Directories of this Directory
  d = opendir(curr_path);
  printf("Directories:\n");
  while (entry = readdir(d)) {
    if (entry->d_type==4) {
      printf("\t %s \n", entry->d_name);
    }
  }

  //Rewinding and making it look nice
  printf("\n");
  rewinddir(d);

  //Getting the files for this directory
  stat(curr_path, &for_size);
  printf("Regular Files:\n");
  while (entry = readdir(d)) {
    if (entry->d_type==8) {
      size = size + for_size.st_size;
      printf("\t %s \t Size: %d\n", entry->d_name, for_size.st_size);
    }
  }
  printf("Size: %d\n", size);

  closedir(d);

  //Getting the Directories of this Directory
  d = opendir(path);
  printf("Directories:\n");
  while (entry = readdir(d)) {
    if (entry->d_type==4) {
      printf("\t %s \n", entry->d_name);
    }
  }

  //Rewinding and making it look nice
  printf("\n");
  rewinddir(d);

  //Getting the files for this directory
  stat(curr_path, &for_size);
  printf("Regular Files:\n");
  while (entry = readdir(d)) {
    if (entry->d_type==8) {
      size = size + for_size.st_size;
      printf("\t %s \t Size: %d\n", entry->d_name, for_size.st_size);
    }
  }
  printf("Size: %d\n", size);

  closedir(d);
  
  return 0;
}
*/
