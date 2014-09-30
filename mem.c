#include <stdio.h>
#include <stdlib.h>

int main() {
  double *d;
  d = (double *)malloc(10 * sizeof(double));
  
  char *c;
  c = (char *)malloc(20 * sizeof(char));

  d[40] = 0;
  c[20] = 0;

  return 0;
}
