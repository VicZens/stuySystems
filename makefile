all: sig.o
	gcc -o Signal sig.o

execution.o: sig.c
	gcc -c sig.c

clean:
	rm *.o
	clear

run:
	./Signal
