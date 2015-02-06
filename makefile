all: pic.o
	gcc -o Gen pic.o

<<<<<<< HEAD
pic.o: pic.c
	gcc -c pic.c

clean:
	rm pic.o
	rm image.ppm
	rm Gen
=======
server.o: server.c tools.h
	gcc -c server.c

client.o: client.c tools.h
	gcc -c client.c

clean:
	rm *.o
	rm Server
	rm Client
	clear
>>>>>>> 5475032ac8ac2c9a7f235cd2d418cbd683aa2095
