#include <stdio.h>
#include <stdlib.h>

typedef struct intList {
  int i;
  struct intList* next;
} intList;

int print_list(intList*);
intList* insert_front(int, intList*);
intList* free_list(intList*);

int main() {
  intList *i;
  i = (intList*)malloc(sizeof(intList));
  (*i).i = 1;
  (*i).next = 0;
  intList *j = insert_front(2, i);
  intList *k = insert_front(3, j);
  intList *l = insert_front(4, k);
  intList *m = insert_front(5, l);
  intList *n = insert_front(6, m);

  printf("Expected Values: 6, 5, 4, 3, 2, 1\n");
  print_list(n);

  printf("Freedom!\n");
  free(n);
  
  printf("Reprinting even though we're not supposed to\n");
  print_list(n);

  return 0;
}

int print_list(intList *i) {
  while (i) {
    printf("%d\n", (*i).i);
    i = i->next;
  }
  return 0;
}

intList* insert_front(int a, intList* i) {
  intList* in = (intList*)malloc(1 * sizeof(intList));
  (*in).i = a;
  (*in).next = i;
  return  in;
}

intList* free_list(intList *i) {
  intList *p = i;
  intList *q = i;

  while (q) {
    free(i);
    i = (*q).next;
  }
  return p;
}
