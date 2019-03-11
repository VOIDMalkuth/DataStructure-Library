Driver : LinkedList.o Driver.o
	cc -o Driver LinkedList.o Driver.o
Driver.o : Driver.c LinkedList.h
	cc -c Driver.c
LinkedList.o : LinkedList.c LinkedList.h
	cc -c LinkedList.c

clean :
	rm Driver Driver.o LinkedList.o