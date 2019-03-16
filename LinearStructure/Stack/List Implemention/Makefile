Driver-Stack : Stack.o Driver-Stack.o LinkedList.o
	cc -o Driver-Stack Stack.o Driver-Stack.o LinkedList.o
Driver-Stack.o : Driver-Stack.c Stack.h
	cc -c Driver-Stack.c
Stack.o : Stack.c Stack.h
	cc -c Stack.c
LinkedList.o : LinkedList.c LinkedList.h
	cc -c LinkedList.c

clean :
	rm Driver-Stack Driver-Stack.o Stack.o LinkedList.o