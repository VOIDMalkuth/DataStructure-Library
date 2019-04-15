#include <stdlib.h>
#include "Queue.h"

Queue *initQueue(void){
    Queue *pQueue = (Queue *)malloc(sizeof(Queue));
    pQueue->count = 0;
    pQueue->front = NULL;
    pQueue->rear = NULL;

    return pQueue;
}

int isQueueEmpty(Queue *pQueue){
    if(0 == pQueue->count)
        return 1;
    return 0;
}

int enQueue(elemType item, Queue *pQueue){
    Node *pNode = (Node *)malloc(sizeof(Node));
    if(NULL == pNode)
        return -1;
    pNode->item = item;
    pNode->next = NULL;
    
    if (isQueueEmpty(pQueue))
        pQueue->front = pNode;
    else
        pQueue->rear->next = pNode;

    pQueue->rear = pNode;
    
    pQueue->count++;
    return 0;
}

int deQueue(elemType *pItem, Queue *pQueue){
    if(NULL == pQueue || isQueueEmpty(pQueue))
        return -1;
    *pItem = pQueue->front->item;
    Node *pTmp = pQueue->front;
    pQueue->front = pQueue->front->next;
    if (NULL == pQueue->front)
        pQueue->rear = NULL;
    free(pTmp);
    pQueue->count--;
    return 0;
}

void freeQueue(Queue **ppQueue){
    Queue *pQueue = *ppQueue;
    Node *pTmp = pQueue->front;
    while (pQueue->front != NULL){
        pTmp = pQueue->front;
        pQueue->front = pQueue->front->next;
        free(pTmp);
    }
    free(pQueue);
    *ppQueue = NULL;
    return;
}