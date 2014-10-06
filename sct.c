#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  typedef struct s {
    int i;
    struct s *next;
  } str;
  
  str x;
  str y;

  x.i = 12;
  y.i = 19;
  
  x.next = &y;
  y.next = 0;

  str *p = &x;

  (*p).x;

  return 0;
}
