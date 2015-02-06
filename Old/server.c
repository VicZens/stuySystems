#include "tools.h"

int main() {
  int from_client;
  int to_client;
  char message[256];

  mkfifo("Roach", 0664);
  from_client = open("Roach", O_RDONLY);
  printf("Waiting for Incoming Connections...\n");

  read(from_client, message, sizeof(message));
  remove("Roach");
  printf("Client said: %s\n", message);
  
  to_client = open(message, O_WRONLY);
  
  strncpy(message, "Hello, Underling...", sizeof(message));
  write(to_client, message, sizeof(message));

  while(1) {
    read(from_client, message, sizeof(message));

    write(to_client, message, sizeof(message));
  }

  close(from_client);
  close(to_client);

  return 0;
}
