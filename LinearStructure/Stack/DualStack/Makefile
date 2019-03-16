Driver-DualStack : DualStack.o Driver-DualStack.o
	cc -o Driver-DualStack DualStack.o Driver-DualStack.o
Driver-DualStack.o : Driver-DualStack.c DualStack.h
	cc -c Driver-DualStack.c
DualStack.o : DualStack.c DualStack.h
	cc -c DualStack.c

clean :
	rm Driver-DualStack Driver-DualStack.o DualStack.o