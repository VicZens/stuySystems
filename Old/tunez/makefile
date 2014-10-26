all: playlist.o
	gcc -o Playlist playlist.o

playlist.o: playlist.c playlist.h
	gcc -c playlist.c

clean:
	rm *.o
	clear

run:
	./Playlist
