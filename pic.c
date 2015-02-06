#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main() {
  int pic = open("image.ppm", O_RDWR | O_TRUNC | O_CREAT | 0664 );
  char init[255] = "P3 500 500 255 "; 
  write(pic, init, strlen(init));

  int x = 0;
  int y = 0;

  char color[255] = "0 0 255 ";
  
  for(x = 0; x < 500; x++) {
    for(y = 0; y < 500; y++) {
      write(pic, color, strlen(color));
    }
  }
  
  close(pic);

  return 0;
}
