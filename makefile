all: server.o client.o
	gcc -o Server server.o
	gcc -o Client client.o

server.o: server.c tools.h
	gcc -c server.c

client.o: client.c tools.h
	gcc -c client.c

clean:
	rm *.o
	rm Server
	rm Client
	clear
