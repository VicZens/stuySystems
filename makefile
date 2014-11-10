all: execution.o
	gcc -o Execute execution.o

execution.o: execution.c
	gcc -c execution.c

clean:
	rm *.o
	clear

run:
	./Execute
