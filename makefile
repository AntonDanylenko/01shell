all: main.o funcs.o
	gcc -o runfile main.o funcs.o

funcs.o: funcs.c funcs.h
	gcc -c funcs.c

main.o: main.c
	gcc -c main.c

run:
	./runfile

clean:
	rm *.o
