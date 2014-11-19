#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo) {
  if(signo==SIGUSR1) {

  }
  if(signo==SIGUSR2) {
    
  }
  if(signo==SIGINT) {
    
  }
}

int main() {
  signal(SIGUSR1, sighandler);
  signal(SIGUSR2, sighandler);
  signal(SIGINT, sighandler);

  //int f;
  //int status;

  int file_who, temp;
  
  file_who = open("sig_who", O_WRONLY | O_TRUNC);

  temp = dup(STDOUT_FILENO);
  dup2(file_who, STDOUT_FILENO);
  printf("Woo! It's gonna work!\n");
  dup2(temp, STDOUT_FILENO);


  return 0;
}
