#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main() {
  int f;
  int x = 10;

  f = fork();
  
  if(f == 0) {
    printf("\tChild: x = %d\n", x);
    x+=45;
    printf("\tChild: x = %d\n", x);
  } else {
    wait(NULL);
    printf("Parent: x = %d\n", x);
  }
  return 0;
}

//Downside of having a shared memory resource
//   File Accessing? A LOT SLOWER.
//Memory is fast, Storage is slow.


/*
  Shared Memory (more IPC - Inter-Process Communication)
  -A segment of heap memory that can bea accessed by multiple processes.
  -
