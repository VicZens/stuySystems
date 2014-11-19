all: run.o shell.o
	gcc -o Shell run.o shell.o

run.o: run.c
	gcc -c run.c

shell.o: shell.c shell.h
	gcc -c shell.c shell.h

clean:
	rm *.o
	rm Shell
	clear

run:
	./Shell
