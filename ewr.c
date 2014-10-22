#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

typedef struct box {
  int num;
  char* word;
} box;

box* set_vars(int n, char* w); 

box* boxes[10];
char* things_to_input[10] = {"Songs seem nice",
			     "I really don't know what I'm doing",
			     "Maybe I should try",
			     "I can't even CS",
			     "To be, or not to be",
			     "That is the question",
			     "I forgot the rest",
			     "Seven is my lucky number",
			     "But it already passed",
			     "Oh so sad"};


int main() {
  int dest;
  dest = open("text", O_RDWR | O_TRUNC);

  //Setting up the Structs
  int i;
  for(i = 0; i < 10; i++) 
    boxes[i] = set_vars(i*7, things_to_input[i]);
  
  //Writing in the file
  
  for(i = 0; i < 10; i++) {
    write(dest, &boxes[i]->num, sizeof(int));
    write(dest, boxes[i]->word, strlen(boxes[i]->word));
  }

  printf("%s\n", strerror(errno));			
  close(dest);
  return 0;
}


box* set_vars(int n, char* w) {
  box* temp = (box*)malloc(sizeof(box));
  temp->num = n;
  temp->word = w;

  return temp; 
}
