#include <stdio.h>
#include <stdlib.h>

int ret;

int Collatz_Helper(long input, int numLength) {
  if (input == 1)
    return numLength;

  if (input % 2 == 0) {
    return Collatz_Helper(input/2, numLength+1);
  } else {
    return Collatz_Helper((3*input)+1, numLength+1);
  }
}

long Collatz(long input) {
  return Collatz_Helper(input, 1);
} 

int main() {
  ret = Collatz(13);
  printf("%d\n", ret);
  return 0;
}
