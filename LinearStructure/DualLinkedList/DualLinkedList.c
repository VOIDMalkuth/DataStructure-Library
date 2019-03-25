#include <stdlib.h>
#include "DualLinkedList.h"

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
    Node *pCur = pNode->next;
    while (pCur != NULL)
    {
        if ((*pCmp)(&item, &(pCur->item)) < 0){
            insertElemAfter(item, pNode);
            return 0;
        }
        if((*pCmp)(&item, &(pNode->item)) == 0){
            return -1;
        }
        pNode = pCur;
        pCur = pCur->next;
    }
    insertElemAfter(item, pNode);

    return 0;
}