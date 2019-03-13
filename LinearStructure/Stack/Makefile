Driver-Stack : Stack.o Driver-Stack.o
	cc -o Driver-Stack Stack.o Driver-Stack.o
Driver-Stack.o : Driver-Stack.c Stack.h
	cc -c Driver-Stack.c
Stack.o : Stack.c Stack.h
	cc -c Stack.c

clean :
	rm Driver-Stack Driver-Stack.o Stack.o