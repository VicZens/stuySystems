#include "tools.h"

int main() {
  int from_server;
  int to_server;
  char message[256];
  char name[256];
  
  sprintf(name, "%d", getpid());
  mkfifo(name, 0644);

  to_server = open("Roach", O_RDONLY);
  write(to_server, name, sizeof(name));

  from_server = open(message, O_RDONLY);
  read(from_server, message, sizeof(message));
  remove(name);
  printf("Server said: %s\n", message);

  while(1) {
    printf("Send to Server: ");
    fgets(message, sizeof(message), stdin);
    write(to_server, message, sizeof(message));
    read(from_server, message, sizeof(message));
  }

  return 0;
}
