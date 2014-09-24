#include <stdio.h>
#include <stdlib.h>

int mylen(char *);
int mycmp(char *, char *);
char * mycpy(char *, char *);
char * mycat(char *, char *);
char * mychr(char *, char *);
char * mystr(char *, char *);

int main() {

  char a[64] = "Imagine";
  char b[] = "Dragons";

  printf("%s\n", mycat(a,b));

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

  if (*a == 0 && *b == 0)
    return 0;
  else if (*a == 0)
    return -1;
  else
    return 1;
}

char * mycpy(char *d, char *s) {
  int i = 0;

  for(i = 0; i < mylen(s); i++)
    d[i] = s[i];

  return d;
}

char * mycat(char *d, char *s) {
  int i = 0;

  while (s[i]) {
    d[mylen(d) + i] = s[i];
    printf("Adding: %c\n", s[i]);
    printf("%c\n", d[mylen(d) + i]);
    i++;
    printf("--Added: %s\n", d);
  }

  return d;
}
