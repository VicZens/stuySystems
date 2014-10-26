#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
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
			     "Seven is my favorite number",
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
    write(dest, boxes[i], sizeof(box));
  }
  
  //Printing out what was written in
  lseek(dest, 0, SEEK_SET);
  box* temp = (box*)malloc(sizeof(box));
  printf("Boxes:\n");
  for(i = 0; i < 10; i++) {
    read(dest, temp, sizeof(box));
    printf("Box #%d --- Num: %d - Phrase: %s\n", i+1, temp->num, temp->word);
  }
  
  printf("\n");

  //Find Box # _
  printf("Which Box would you like to investigate?\n");
  printf("I would like to investigate Box # ");
  scanf("%d", &i);
  lseek(dest, (i-1)*sizeof(box), SEEK_SET);
  box* atemp = (box*)malloc(sizeof(box));

  read(dest, atemp, sizeof(box));
  printf("Box #%d --- Num %d - Phrase: %s\n", i, atemp->num, atemp->word);

  printf("\n");

  //Modify Box # _
  printf("Which Box would you like to modify?\n");
  printf("I would like to modify Box # ");
  scanf("%d", &i);
  int new_num;
  char* new_phrase;

  printf("New Int: ");
  scanf("%d", &new_num);

  printf("New Phrase: ");
  scanf("%s", new_phrase);
  printf("\n");

  printf("%s\n", &new_phrase);
  
  boxes[i-1] = set_vars(new_num, new_phrase);
  
  //Lazy, Hehe.
  lseek(dest, 0, SEEK_SET);
  for(i = 0; i < 10; i++) {
    write(dest, boxes[i], sizeof(box));
  }

  //Printing out new Boxes
  lseek(dest, 0, SEEK_SET);
  box* btemp = (box*)malloc(sizeof(box));
  printf("Boxes:\n");
  for(i = 0; i < 10; i++) {
    read(dest, btemp, sizeof(box));
    printf("Box #%d --- Num: %d - Phrase: %s\n", i+1, btemp->num, btemp->word);
  }
  
  printf("\n");
  

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
