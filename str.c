#include <stdio.h>
#include <stdlib.h>

int mylen(char *);
int mycmp(char *, char *);
char * mycpy(char *, char *);
char * mycat(char *, char *);
char * mychr(char *, char *);
char * mystr(char *, char *);

int main() {

  char a[] = "Helln";
  char b[] = "Hellno";

  //printf("mylen 7 = %d\n", mylen(a));
  //printf("%c\n", *mycpy(a,b));

  printf("%d\n", mycmp(a,b));

  return 0;
}

int mylen(char c[]) {
  int i = 0;
  while (c[i])
    i++;
  return i;
}

int mycmp(char *a, char *b) {
  int i = 0;

  while (*a || *b) {
    if (*(a+i) > *(b+i))
      return 1;
    if (*(a+i) < *(b+i))
      return -1;
    i++;
  }
  
  return 0;
}

char * mycpy(char *d, char *s) {
  int i = 0;

  for(i = 0; i < mylen(s); i++) {
    d[i] = s[i];
  }

  return d;
}

