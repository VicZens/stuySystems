#include <stdio.h>
#include <stdlib.h>

int ret;
int i;
int ans = 999999;
int ansLength, currLength;

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

long Collatz_Solver() {
  ansLength = Collatz(ans);
  for(i = 999998; i > 0; i=i-1) {
    currLength = Collatz(i);
    if (currLength > ansLength) {
      ansLength = currLength;
      ans = i;
    }
  }
  return ans;
}

int main() {
  ret = Collatz_Solver();

  printf("%d\n", ret);
  return 0;
}
