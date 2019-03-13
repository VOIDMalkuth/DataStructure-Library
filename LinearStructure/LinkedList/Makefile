Driver-LinkedList : LinkedList.o Driver-LinkedList.o
	cc -o Driver-LinkedList LinkedList.o Driver-LinkedList.o
Driver-LinkedList.o : Driver-LinkedList.c LinkedList.h
	cc -c Driver-LinkedList.c
LinkedList.o : LinkedList.c LinkedList.h
	cc -c LinkedList.c

clean :
	rm Driver-LinkedList Driver-LinkedList.o LinkedList.o