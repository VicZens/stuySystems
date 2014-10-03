all: sct.o
	gcc sct.o

sct.o: sct.c
	gcc -c sct.c
