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
    printf("End of list: %d\n\n", pHead->pEnd->item);

    printf("Deleting Node 1...\n");
    deleteNode(pHead, 1);
    traverseList(pHead, printList);
    putchar('\n');

    printf("ListLength: %d\n", getListLength(pHead));
    printf("End of list: %d\n\n", pHead->pEnd->item);

    printf("Deleting Node 9(Last)...\n");
    deleteNode(pHead, 9);
    traverseList(pHead, printList);
    putchar('\n');

    printf("ListLength: %d\n", getListLength(pHead));
    printf("End of list: %d\n\n", pHead->pEnd->item);

    printf("Sorting List...\n");
    sortList(pHead, cmp);
    traverseList(pHead, printList);
    putchar('\n');

    printf("ListLength: %d\n", getListLength(pHead));
    printf("End of list: %d\n\n", pHead->pEnd->item);

    return 0;
}
