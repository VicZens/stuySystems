#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(DIR* d) {
  //Declaring my Variables
  char current_path[255];
  
  int size;
  int total_size;

  DIR* c_d;
  struct dirent* curr_dir;
  struct stat* to_get_sizes;

  //Setting Current Working Directory and Printing it
  getcwd(current_path, sizeof(current_path));
  printf("Current Working Directory: \n\t %s \n\n", current_path);

  //Right, I have to open the Directory before I can use it...
  c_d = opendir(current_path);

  //Printing out the Directories
  printf("Directories???\n");
  while (curr_dir = readdir(c_d))
    if (curr_dir->d_type == 4)
      printf("\t %s \n", curr_dir->d_name);
  
  //Final Lap...?
  rewinddir(c_d);
  
  //Printing out the Files
  printf("Files!!!\n");
  while (curr_dir = readdir(c_d))
    if (curr_dir->d_type == 8) {
      stat(curr_dir->d_name, to_get_sizes);
      printf("\t %s \t Size: %d kBs\n", curr_dir->d_name, to_get_sizes->st_size/1000);
    }

  
  //Annnnndddd doing this all over again for a select directory
  rewinddir(d);

  printf("Directories???\n");
  while (curr_dir = readdir(d))
    if (curr_dir->d_type == 4)
      printf("\t %s \n", curr_dir->d_name);

  rewinddir(d);
  
  printf("Files!!!\n");
  while (curr_dir = readdir(d))
    if (curr_dir->d_type == 8) {
      stat(curr_dir->d_name, to_get_sizes);
      printf("\t %s \t Size: %d kBs\n", curr_dir->d_name, to_get_sizes->st_size/1000);
    }
  
  //Doesnt work???!!!
  


  return 0;
}
