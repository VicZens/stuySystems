all: list.o
	gcc -o Jujubes list.o

list.o:
	gcc -c list.c

clean:
	clear;
	rm *.o;
	clear;

run:
	./Jujubes
