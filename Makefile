all: statfile.o
	gcc -o statfile.out statfile.o

statfile.o: statfile.c
	gcc -c statfile.c

clean:
	rm -f *.o *.out statfile

run:
	./statfile.out
