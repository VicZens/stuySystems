#include <stdio.h>
#include <stdlib.h>

//Works with all the cases given and more, but will not run
//to find the answer because it uses up too much memory.

int i, start;
long ret;

long Triangular_Helper(long input, long current, int counter) {
  if (input==current)
    return counter+1;

  if (input%current==0) {
    return Triangular_Helper(input, current+1, counter+1);
  } else {
    return Triangular_Helper(input, current+1, counter);
  }
}

long Triangular(long input) {
  return Triangular_Helper(input,1,0);
}

long Triangular_Solver() {
  start = 0;
  for(i = 1; i != 0; i=i+1) {
    start = start + i;
    if (Triangular(start) > 500) {
      i = 0;
    }
  }

  return start;
}

int main () {
  ret = Triangular(76576500);
  printf("%ld\n", ret);
  return 0;
}
