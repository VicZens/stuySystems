#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

int for_who_nation();
int ps_kids();
int show_hand();

int checkwho, checkps;

static void sighandler(int signo) {
  if(signo==SIGUSR1) {
    for_who_nation();
  }
  if(signo==SIGUSR2) {
    ps_kids();
  }
  if(signo==SIGINT) {
    show_er();
  }
}

int main() {
  signal(SIGUSR1, sighandler);
  signal(SIGUSR2, sighandler);
  signal(SIGINT, sighandler);
  int f;

  printf("Please do not use kill -30 <pid> or kill -31 <pid>, Mr DW.\n");
  printf("They cannot be overran. If you meant to make us frustrated,\n");
  printf("it has worked really well. Please use kill -10 <pid> for\n");
  printf("SIGUSR1 and kill -12 <pid> for SIGUSR2.\n\n");
  printf("Thank You\n\n");

  while (!f) {
    sleep(1);
    printf("PID:\t%d\n", getpid());
  }
  return 0;
}


int for_who_nation() {
  int file_who, temp, status, f;
  
  if (checkwho)
    file_who = open("who", O_WRONLY | O_APPEND);
  else
    file_who = open("who", O_WRONLY | O_TRUNC);
  checkwho++;
  temp = dup(STDOUT_FILENO);
  dup2(file_who, STDOUT_FILENO);
  f = fork();
  if (f==0)
    execlp("who", " ", NULL);
  else
    wait(&status);
  dup2(temp, STDOUT_FILENO);

  return 0;
}

int ps_kids() {
  int file_ps, temp, status, f;

  if (checkps)
    file_ps = open("ps", O_WRONLY | O_APPEND);
  else
    file_ps = open("ps", O_WRONLY | O_TRUNC);
  checkps++;
  temp = dup(STDOUT_FILENO);
  dup2(file_ps, STDOUT_FILENO);
  f = fork();
  if (f==0)
    execlp("ps", " ", NULL);
  else
    wait(&status);
  dup2(temp, STDOUT_FILENO);

  return 0;
}

int show_er() {
  int f, status;
  f = fork();

  if (f==0) {
    execlp("cat", " ", "who", NULL);
  }
  else {
    wait(&status);
    execlp("cat", " ","ps", NULL);
  }

  return 0;
}
