#include <stdio.h>
#include <stdlib.h>

//Works with a lot of numbers, but due to segmentation fault, and not
//enough memory, I was not able to run the function to its answer,
//76576500. 

int Triangular_Helper(long input, long current, int counter);
int Triangular(long input);
int Triangular_Solver();

int start = 0;
int bool = 1;


int main () {
  int ret;

  ret = Triangular(76576500);
  printf("%d\n", ret);

  return 0;
}

/*
int Triangular_Solver() {
  while (bool) {
    if (Triangular(start) > 5) {
      printf("Works %d", start);
      bool = 0;
    } else {
      printf("Works %d", start);
      start++;
    }
  }
  return start;
}
*/

int Triangular(long i) {
  return Triangular_Helper(i,1,0);
}

int Triangular_Helper(long input, long current, int counter) {
  if (input==current)
    return counter+1;

  if (input%current==0)
    return Triangular_Helper(input, current+1, counter+1);
  else
    return Triangular_Helper(input, current+1, counter);
 
}





