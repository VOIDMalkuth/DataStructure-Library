#include <stdio.h>
#include <stdlib.h>
#include "LinearStructure/DualLinkedList/DualLinkedList.h"

Node *initList(void)
{
    Head *pHead = (Head *)malloc(sizeof(Head));
    pHead->prev = NULL;
    pHead->next = NULL;
    return pHead;
}

void freeList(Head **ppHead)
{
    Head *pHead = *ppHead;
    while (pHead->next != NULL)
    {
        pHead = pHead->next;
        free(pHead->prev);
    }
    free(pHead);
    *ppHead = NULL;
    return;
}

//Insert after pCur
int insertNodeAfter(Node *pNode, Node *pCur)
{
    if (pCur == NULL)
        return -1;
    pNode->next = pCur->next;
    pNode->prev = pCur;
    if (pNode->next != NULL)
        pNode->next->prev = pNode;
    pCur->next = pNode;
    return 0;
}

int insertElemAfter(elemType elem, Node *pCur)
{
    Node *pNode = (Node *)malloc(sizeof(Node));
    pNode->item = elem;
    pNode->next = NULL;
    pNode->prev = NULL;
    int status = insertNodeAfter(pNode, pCur);
    return status;
}

int deleteNode(Node *pNode){
    if (pNode->prev == NULL)
        return -1;

    pNode->prev->next = pNode->next;
    if (pNode->next != NULL)
        pNode->next->prev = pNode->prev;
    free(pNode);
    return 0;
}

int swapElem(Node *pNode_1, Node *pNode_2){
    if ((pNode_1 == NULL) || pNode_2 == NULL)
        return -1;
    if(pNode_1 == pNode_2)
        return 0;

    elemType elem = pNode_1->item;
    pNode_1->item = pNode_2->item;
    pNode_2->item = elem;
    return 0;
}

void sortList(Head *pHead, int (*pCmp)(const void *, const void *)){
    Node *pNode1, *pNode2;
    for (pNode1 = pHead->next; pNode1 != NULL; pNode1 = pNode1->next){
        for (pNode2 = pNode1->next; pNode2 != NULL; pNode2 = pNode2->next){
            if((*pCmp)(&(pNode1->item), &(pNode2->item)) > 0){
                swapElem(pNode1, pNode2);
            }
        }
    }
    return;
}

int insertOrderly(elemType item, Head *pHead, int (*pCmp)(const void *, const void *)){
    Node *pNode = pHead;
    while (pNode->next != NULL)
    {
        pNode = pNode->next;
        printf("%p\n", pNode);
        if ((*pCmp)(&item, &(pNode->item)) < 0){
            insertElemAfter(item, pNode->prev);
            return 0;
        }
        else if((*pCmp)(&item, &(pNode->item)) == 0){
            return -1;
        }
        else
            continue;
    }

    if((pHead != pNode) && ((*pCmp)(&item, &(pNode->item)) == 0))
        return -1;
    else
        insertElemAfter(item, pHead);

    return 0;
}


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
    for (i = 0; i < 10; i++)
        insertOrderly(a[i], pHead, cmp);
    pNode = pHead->next;
    while(pNode != NULL){
        printf("%d ",pNode->item);
        pNode = pNode->next;
    }
    putchar('\n');

    freeList(&pHead);

    return 0;
}
