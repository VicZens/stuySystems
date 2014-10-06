#include <stdio.h>
#include <stdlib.h>

typedef struct intList {
  int i;
  struct intList *next;
} intList;

int print_list(intList *i);
intList* insert_front(intList *i, int a);
intList* free_list(intList *i);

int main() {
  intList i;
  i.i = 2;
  insert_front(&i, 1);
  printf("HereOne\n");
  print_list(&i);
  printf("HereTwo\n");
  return 0;
}

int print_list(intList *i) {
  while (i->next) {
    printf("%d\n", (*i).i);
  }
  printf("HereThree\n");
  return 0;
}

intList* insert_front(intList *i, int a) {
  intList in;
  in.i = a;
  in.next = i;
  return  &in;
}

/*
intList* free_list(intList *i) {
  intList *p = *i;
  while (i->next) {
  }
}
*/
