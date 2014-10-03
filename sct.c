#include <stdio.h>
#include <stdlib.h>

int main() {
  typedef struct s {
    int i;
    struct s *next;
  } str;
  
  str x;
  str y;

  x.i = 12;
  x.next = &y;

  printf("%lu\n", *x.next);

  return 0;
}
