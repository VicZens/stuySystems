all: list.o
	gcc list.o

list.o:
	gcc -c list.c

clean:
	rm *.o;
	rm *~;
