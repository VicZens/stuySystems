//Minutia for December 2nd, 2014
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/shm.h> //Only after Shared Memory
#include <sys/ipc.h> //Only after Shared Memory

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
  -Shared memory is accessed via some key that is knowon by any process 
  that needs to access it
  -Shared memory does not get released when a program exits


  -----------------------------------------------------------------------------
5 Key Shared Memory Operations:
  
1 - Creating the Segment
  -Only happens once

2 - Accessing the Segment
  -Should happen once per process

3 - Attaching the Segment to a variable
  -Should happen once per process
  -Will have access as if the segment was a variable

4 - Detaching the Segment from a variable
  -Should happen once per process
  
5 - Removing the Segment
  -Only happens once
  -----------------------------------------------------------------------------

shmget - <sys/shm.h>, <sys/ipc.h>
  -Creates or accesses a shared memory segment
  -Returns a shared memory descriptor (similar idea to a file descriptor), 
  or -1 if it fails.
  
shmget( key, size, flags )
  
  key
  -Unique integer identifier for the shared memory segment
  size
  -The amount of memory that you request
  flags
  -Signals whether to create the segment or not
  -Includes permissions for the segment
  -Combine with bitwise or
  
  IPC_CREAT
  -Creates the segment
  -Will set all values to 0
  IPC_EXCL
  -Fails if the segment already exists and IPC_CREAT is on
*/

int working_shmget_function() {
  //Only this part is in notes
  int sd;
  sd = shmget ( 24601, 1024, IPC_CREAT | 0664 );
  //Only this part is in notes
  return 0;
}

/*
shmat - <sys\shm.h>, <sys/ipc.h>
  -Attach a shared emmroy segment to a variable
  -Returns a pointer to the segment, o0r -1
  
  shmat(descriptor, address, flags)

  descriptor
  the return value of shmget

  address
  if 0, the OS will provide the appropriate address
  
  flags Usually 0, there is one useful flag

  SHM_RDONLY: makes the memory read only
