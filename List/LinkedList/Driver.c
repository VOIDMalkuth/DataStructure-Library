#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef int elemType;

int a[10] = {1, 5, 62, 93, 10, 5, 36, 2, 1, -1};

void printList(elemType *pElem){
    printf("%d ", *pElem);
    return;
}

int cmp(const void *a, const void *b){
    return (*(int *)a) - (*(int *)b);
}

int main(void){
    Head *pHead = initList();
    int i = 0;
    for (i = 0; i < 10; i++)
        insertElem(pHead, a[i]);

    traverseList(pHead, printList);
    putchar('\n');

    deleteNode(pHead, 5);
    traverseList(pHead, printList);
    putchar('\n');

    printf("ListLength: %d\n", getListLength(pHead));

    sortList(pHead, cmp);
    traverseList(pHead, printList);
    putchar('\n');

    return 0;
}
