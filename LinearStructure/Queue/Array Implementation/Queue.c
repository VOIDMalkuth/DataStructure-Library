#include <stdlib.h>
#include "Queue.h"

Queue *initQueue(int n){
    Queue *pQueue = (Queue *)malloc(sizeof(Queue));
    pQueue->head = 0;
    pQueue->end = 0;
    pQueue->capacity = n;
    pQueue->pSpace = (char *)malloc(sizeof(elemType) * n);
    return pQueue;
}

int isQueueEmpty(Queue *pQueue){
    return ((pQueue->head == pQueue->end) ? 1 : 0);
}

int isQueueFull(Queue *pQueue){
    return (((pQueue->end + 1) % pQueue->capacity) == pQueue->head) ? 1 : 0;
}

int enQueue(elemType item, Queue *pQueue){
    if (isQueueFull(pQueue))
        return -1;
    else{
        (pQueue->pSpace)[pQueue->end] = item;
        pQueue->end = (pQueue->end + 1) % pQueue->capacity;
        return 0;
    }
}

int deQueue(elemType *pItem, Queue *pQueue){
    if(isQueueEmpty(pQueue))
        return -1;
    else{
        *pItem = (pQueue->pSpace)[pQueue->head];
        pQueue->head = (pQueue->head + 1) % pQueue->capacity;
        return 0;
    }
}

void freeQueue(Queue **ppQueue){
    Queue *pQueue = *ppQueue;
    free(pQueue->pSpace);
    *ppQueue = NULL;
    return;
}