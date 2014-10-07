#include <stdio.h>
#include <stdlib.h>

typedef struct musicList {
  char artist[];
  char title[];
  struct intList* next;
} intList;

int print_list(musicList*);
musicList* insert_front(int, musicList*);
musicList* free_list(musicList*);
int mycmp(char* a, char* b);

int main() {
  musicList origin;

  char artest[256];
  char song[256];
  (*origin).artist = scanf("%s", artest);
  (*origin).title = scanf("%s", song);


  return 0;
}

int print_list(musicList *i) {
while (i) {
printf("%d\n", (*i).i);
    i = i->next;
  }
  return 0;
}



musicList* insert_front(int a, musicList* i) {
  musicList* in = (musicList*)malloc(1 * sizeof(musicList));
  (*in).i = a;
  (*in).next = i;
  return  in;
}

musicList* free_list(musicList* i) {
  musicList *p = i;

  while (i) {
    free(i);
    i = (*i).next;
  }
  return p;
}

int mycmp(char* a, char* b) {
  int i = 0;

  while (*(a+i) || *(b+i)) {
    if (*(a+i) > *(b+i))
      return 1;
    if (*(a+i) < *(b+i))
      return -1;
    i++;
  }

  return 0;
}
