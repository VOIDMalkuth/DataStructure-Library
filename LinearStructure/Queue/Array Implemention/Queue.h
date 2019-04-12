typedef char elemType;

typedef struct Queue{
    elemType *pSpace;
    int head;
    int end;
    int capacity;
} Queue;

Queue *initQueue(int n);

int isQueueEmpty(Queue *pQueue);

int isQueueFull(Queue *pQueue);

int enQueue(elemType item, Queue *pQueue);

int deQueue(elemType *pItem, Queue *pQueue);