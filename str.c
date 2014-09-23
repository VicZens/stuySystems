#include <stdio.h>
#include <stdlib.h>

int mylen(char *);
int mycmp(char *, char *);
char * mycpy(char *, char *);
char * mycat(char *, char *);
char * mychr(char *, char *);
char * mystr(char *, char *);

int main() {

  char a[] = "Dragons";
  char b[] = "Imagine";

  printf("mylen 7 = %d\n", mylen(a));

  printf("%c\n", *mycpy(a,b));

  return 0;
}

int mylen(char c[]) {
  int i = 0;
  while (c[i])
    i++;
  return i;
}

int mycmp(char *a, char *b) {
  
}

char * mycpy(char *d, char *s) {
  int i = 0;

  for(i = 0; i < mylen(s); i++) {
    d[i] = s[i];
  }

  return d;
}

