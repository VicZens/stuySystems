#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sighandler(int signal) {
  if(signo==SIGUSR1) {

  }
  if(signo==SIGUSR2) {

  }
  if(signo==SIGINT) {

  }

}

int main() {
  
  signal(SIGUSR1, sighander);
  signal(SIGUSR2, sighander);
  signal(SIGINT, sighander);

  return 0;
}
