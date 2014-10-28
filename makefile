all: direct.o
	gcc -o Directory direct.o

direct.o: direct.c
	gcc -c direct.c

clean:
	rm *.o
	clear

run:
	./Directory ~/stuySystems/Old
