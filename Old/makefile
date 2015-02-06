all: server.o client.o
	gcc -o Server server.o
	gcc -o Client client.o

server.o: server.c tools.h
	gcc -c server.c tools.h

client.o: client.c tools.h
	gcc -c client.c tools.h

clean:
	rm *.o
	clear
