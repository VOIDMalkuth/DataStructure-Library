#include <stdio.h>
#include "Queue.h"

int main(void){
    Queue *pQueue = initQueue(5);

    char j;

    for (int i = 'a'; i < 'h'; i++)
        printf("%d ", enQueue(i, pQueue));

    putchar('\n');

    for (int i = 'a'; i < 'c'; i++){
        printf("%d:", deQueue(&j, pQueue));
        printf("%c ", j);
    }

    putchar('\n');

    for (int i = 's'; i < 'z'; i++)
        printf("%d ", enQueue(i, pQueue));

    putchar('\n');

    for (int i = 'a'; i < 'h'; i++){
        printf("%d:", deQueue(&j, pQueue));
        printf("%c ", j);
    }

    return 0;
}