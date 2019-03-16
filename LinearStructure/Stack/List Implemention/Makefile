Driver-Stack : Stack.o Driver-Stack.o
	cc -o Driver-Stack Stack.o Driver-Stack.o
Driver-Stack.o : Driver-Stack.c Stack.h
	cc -c Driver-Stack.c
Stack.o : Stack.c Stack.h LinkedList.o
	cc -c Stack.c -o stack.o
	ld -r -s -o Stack.o stack.o LinkedList.o
LinkedList.o : LinkedList.c LinkedList.h
	cc -c LinkedList.c

clean :
	rm Driver-Stack Driver-Stack.o Stack.o LinkedList.o stack.o