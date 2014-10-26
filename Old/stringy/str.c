#include <stdio.h>
#include <stdlib.h>

int mylen(char *);
int mycmp(char *, char *);
char * mycpy(char *, char *);
char * mycpyn(char *, char *, int);
char * mycat(char *, char *);
char * mycatn(char *, char *, int);
char * mychr(char *, char);
char * mystr(char *, char *);

int main() {
  char a[128] = "These";
  char b[128] = "are";
  char c[128] = "the";
  char d[128] = "test";
  char e[128] = "cases";
  char f[128] = "car";
  char g[128] = "aren";
  char h[128] = "abcdefghijklmnopqrstuvwxyzzzzzzzzzzzz";
  char i[128] = "cases";
  char j[128] = "casesss";
  char k[128] = "arent";
  char l[128] = "longwords";
  char m[128] = "neededlongwords";
  char n[128] = "lastlongwordormaybenot";

  char s[128];
  char t[128];
  char u[128];

  char v[128];
  char w[128];

  char x[128];
  char y[128];
  char z[128];
  
  printf("---mylen Testing---\n");
  printf("Test One:\n These - - - Length: 5\n Run: %d\n", mylen(a));
  printf("Test Two:\n are - - - Length: 3\n Run: %d\n", mylen(b));
  printf("Test Three:\n abcdefghijklmnopqrstuvwxyz - - - Length: 26\n Run: %d\n", mylen(h));
  printf("\n");

  printf("---mycmp Testing---\n");
  printf("Test One:\n Word 1: cases - Word 2: car\n Run: %d\n", mycmp(e, f));
  printf("Test Two:\n Word 1: cases - Word 2: cases\n Run: %d\n", mycmp(e, i));
  printf("Test Three:\n Word 1: are - Word 2: the\n Run: %d\n", mycmp(b, c));
  printf("Test Four:\n Word 1: casesss - Word 2: cases\n Run: %d\n", mycmp(j, e));
  printf("Test Five:\n Word 1: aren - Word 2: arent\n Run: %d\n", mycmp(g, k));
  printf("\n");

  printf("---mycpy Testing---\n");
  printf("Before Copying:\n");
  printf(" x: %s\n y: %s\n z: %s\n", x, y, z);
  printf("Copying:\n %s --> x\n %s --> y\n %s --> z\n", h, i, j);
  mycpy(x, h);
  mycpy(y, i);
  mycpy(z, j);
  printf("After Copying:\n");
  printf(" x: %s\n y: %s\n z: %s\n", x, y, z);
  printf("\n");

  printf("---mycpyn Testing---\n");
  printf("Before Copying:\n");
  printf(" s: %s\n t: %s\n u: %s\n", s, t, u);
  printf("Copying:\n %s - 6 --> s\n %s - 7 --> t\n %s - 10 --> u\n", l, m, n);
  mycpyn(s, l, 6);
  mycpyn(t, m, 7);
  mycpyn(u, n, 10);
  printf("After Copying:\n");
  printf(" s: %s\n t: %s\n u: %s\n", s, t, u);
  printf("\n");

  printf("---mycat Testing---\n"); 
  printf("Before Catting:\n");
  printf(" s: %s\n m: %s\n h: %s\n", s, m, h);
  printf("Catting:\n %s --> s\n %s --> m\n %s --> h\n", h, c, d);
  mycat(s, h);
  mycat(m, c);
  mycat(h, d);
  printf("After Catting:\n");
  printf(" s: %s\n m: %s\n h: %s\n", s, m, h);
  printf("\n");

  printf("---mycatn Testing---\n"); 
  printf("Before Catting:\n");
  printf(" s: %s\n m: %s\n h: %s\n", s, m, h);
  printf("Catting:\n %s - 8 --> s\n %s - 3 --> m\n %s - 2 --> h\n", h, c, d);
  mycatn(s, h, 8);
  mycatn(m, c, 3);
  mycatn(h, d, 2);
  printf("After Catting:\n");
  printf(" s: %s\n m: %s\n h: %s\n", s, m, h);
  printf("\n");
  
  printf("---mychr Testing---\n");
  printf("Test One:\n Searching in: %s\n Searching for: %c\n", e, 'e');
  printf(" Pointer: %p - Points at: %c\n", mychr(e,'e'), *mychr(e,'e'));
  printf("Test Two:\n Searching in: %s\n Searching for: %c\n", h, 't');
  printf(" Pointer: %p - Points at: %c\n", mychr(h,'t'), *mychr(h,'t'));
  printf("\n");

  printf("---mystr Testing---\n");
  printf("Test One:\n Searching in: %s\n Searching for: %s\n", n, "long");
  printf(" Pointer: %p - Points at: %s\n", mystr(n,"long"), *mystr(n,"long"));
  
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

  while (*(a+i) || *(b+i)) {
    if (*(a+i) > *(b+i))
      return 1;
    if (*(a+i) < *(b+i))
      return -1;
    i++;
  }

  return 0;
}

char * mycpy(char *d, char *s) {
  int i;

  for(i = 0; i < mylen(s); i++)
    d[i] = s[i];

  return d;
}

char * mycpyn(char *d, char *s, int i) {
  int j;

  for(j = 0; j < i; j++)
    d[j] = s[j];

  return d;
}

char * mycat(char *d, char *s) {
  int i = 0;
  int l = mylen(d);

  while (s[i]) {
    d[l + i] = s[i];
    i++;
  }

  return d;
}

char * mycatn(char *d, char *s, int j) {
  int i = 0;
  int l = mylen(d);

  while (s[i] && i < j) {
    d[l + i] = s[i];
    i++;
  }

  return d;
}

char * mychr (char *s, char c) {
  int i = 0;
  char a[] = "No such Char found";
  char *p;
  *p = &a;

  while (s[i]) {
    if (s[i] = c)
      *p = s[i];
    i++;
  }

  return p;
}

char * mystr (char *s, char *c) {
  int i;
  int j;
  char *p;

  while (s[i]) {

    if (s[i] == c[j]) {
      for (j = 0; j < mylen(c); j++) {
	if (s[i+j] != c[j])
	  j = mylen(c);

	if (s[i+j] == c[mylen(c)-1] && j == mylen(c) - 1) {
	  p = s[i];
	  j = mylen(c);
	}
      }
      j = 0;
    }

    i++;
  }

  return p;
}
