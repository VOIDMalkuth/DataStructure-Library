typedef char elemType;

typedef struct Node{
    elemType item;
    struct Node *next;
} Node;

typedef struct Queue
{
    int count;
    struct Node *front;
    struct Node *rear;
} Queue;

Queue *initQueue(void);

int isQueueEmpty(Queue *pQueue);

int enQueue(elemType item, Queue *pQueue);

int deQueue(elemType *pItem, Queue *pQueue);

void freeQueue(Queue **ppQueue);