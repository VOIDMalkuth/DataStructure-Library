Driver-Queue : Queue.o Driver-Queue.o
	cc -o Driver-Queue Queue.o Driver-Queue.o
Driver-Queue.o : Driver-Queue.c Queue.h
	cc -c Driver-Queue.c
Queue.o : Queue.c Queue.h
	cc -c Queue.c

clean :
	rm Driver-Queue Driver-Queue.o Queue.o