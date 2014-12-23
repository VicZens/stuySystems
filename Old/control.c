#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/shm.h> 
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

int main() {
  int shm_descript;
  shm_descript = shmget(ftok("story.txt", 'd'), sizeof(int), IPC_CREAT | 0664);
  
  
  return 0;
}
