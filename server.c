#include "tools.h"

int from_client;
int to_client;
char message[256];

int main() {
  mkfifo("Pipe", 0664);
  printf("Ready! Waiting for Incoming Connections...\n");
  from_client = open("Pipe", O_RDONLY);
  
  read(from_client, message, sizeof(message));
  printf("Client said: %s\n", message);
  remove("Pipe");
  
  to_client = open(message, O_WRONLY);
  strncpy(message, "Message has been recieved", 256);
  write(to_client, message, 256);

  printf("Finished\n");
  
  return 0;
}

/*
  read(from_client, message, sizeof(message));
  remove("Pipe");
  printf("Client said: %s\n", message);
  
  to_client = open(message, O_WRONLY);
  
  strncpy(message, "Hello, Underling...", sizeof(message));
  write(to_client, message, sizeof(message));

  while(1) {
  read(from_client, message, sizeof(message));
  printf("Client said: %s\n", message);
  write(to_client, message, sizeof(message));
  }

  close(from_client);
  close(to_client);
*/
