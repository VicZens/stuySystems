#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  double *d;
  char *c;

  d = (double *)malloc(10 * sizeof(double));  
  c = (char *)malloc(20 * sizeof(char));

  d[0] = 7.17;
  c[0] = 0;
  strcpy(c, "wuhoo");

  printf("%lf\n", d[0]);
  printf("%s\n", c);

  free(d);
  free(c);

  return 0;
}
