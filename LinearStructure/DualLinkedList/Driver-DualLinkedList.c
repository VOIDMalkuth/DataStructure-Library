#include <stdio.h>
#include <stdlib.h>
#include "DualLinkedList.h"

typedef int elemType;

int a[10] = {1, 5, 62, 93, 10, 5, 36, 2, 1, -1};

int cmp(const void *a, const void *b){
    return (*(int *)a) - (*(int *)b);
}

int main(void){
    Head *pHead = initList();
    Node *pNode = pHead->next;
    int i = 0;
    for (i = 0; i < 10; i++)
        insertElemAfter(a[i], pHead);

    while(pNode != NULL){
        printf("%d ",pNode->item);
        pNode = pNode->next;
    }
    putchar('\n');
    pNode = pHead->next;
    while(pNode != NULL){
        printf("%d ",pNode->item);
        pNode = pNode->next;
    }
    putchar('\n');

    printf("Deleting Node 1...\n");
    deleteNode(pHead->next);
    pNode = pHead->next;
    while (pNode != NULL){
        printf("%d ",pNode->item);
        pNode = pNode->next;
    }
    putchar('\n');
    pNode = pHead->next;

    while(pNode->next != NULL)
        pNode = pNode->next;
    printf("Deleting Node 9(Last)...\n");
    deleteNode(pNode);
    pNode = pHead->next;
    while(pNode != NULL){
        printf("%d ",pNode->item);
        pNode = pNode->next;
    }
    putchar('\n');
    pNode = pHead->next;

    printf("Sorting List...\n");
    sortList(pHead, cmp);
    while(pNode != NULL){
        printf("%d ",pNode->item);
        pNode = pNode->next;
    }
    putchar('\n');
    pNode = pHead->next;

    printf("Freeing List\n");
    freeList(&pHead);
    printf("pHead: %p\n", pHead);

    printf("Orderly insert\n");
    pHead = initList();
    for (i = 0; i < 10; i++){
        insertOrderly(a[i], pHead, cmp);
        pNode = pHead->next;
        while(pNode != NULL){
            printf("%d ",pNode->item);
            pNode = pNode->next;
        }
        putchar('\n');
    }

    

    return 0;
}
