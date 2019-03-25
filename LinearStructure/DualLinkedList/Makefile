Driver-DualLinkedList : DualLinkedList.o Driver-DualLinkedList.o
	cc -o Driver-DualLinkedList DualLinkedList.o Driver-DualLinkedList.o
Driver-DualLinkedList.o : Driver-DualLinkedList.c DualLinkedList.h
	cc -c Driver-DualLinkedList.c
DualLinkedList.o : DualLinkedList.c DualLinkedList.h
	cc -c DualLinkedList.c

clean :
	rm Driver-DualLinkedList Driver-DualLinkedList.o DualLinkedList.o