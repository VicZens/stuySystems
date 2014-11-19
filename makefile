all: run.o shell.o
	gcc -o Shell run.o shell.o

run.o: run.c
	gcc -c run.c

shell.o:
	gcc -o shell.c shell.h

clean:
	rm *~
	clear

run:
	./Shell
