#include "tools.h"

int from_server;
int to_server;
char message[256];
char name[256];

int main() {
  sprintf(name, "%d", getpid());
  mkfifo(name, 0664);
  
  to_server = open("Pipe", O_WRONLY);
  write(to_server, name, sizeof(name));

  from_server = open(message, O_RDONLY);
  read(from_server, message, 256);
  printf("Server: %s\n", message);
  remove(name);

  printf("Finished\n");

  return 0;
}

/*
  from_server = open(message, O_RDONLY);
  read(from_server, message, sizeof(message));
  printf("Server said: %s\n", message);
  remove(name);

  while(1) {
  printf("Send to Server: ");
  fgets(message, sizeof(message), stdin);
  write(to_server, message, sizeof(message));
  read(from_server, message, sizeof(message));
  printf("Server said: %s", message);
  }
*/
