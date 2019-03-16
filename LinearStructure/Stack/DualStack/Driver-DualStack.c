/* Author: Void-Malkuth
 * Date: 2019.3.16
 */

#include <stdio.h>
#include <string.h>
#include "DualStack.h"

int main(void){
    char str[20] = "abcdefghijklmn";
    printf("Initing Stack...\n");
    Stack *pStack = initDualStack(10);
    printf("pStack: %p", pStack);
    printf("\nStack0length: %d Stack1length: %d Size: %d\n", getStackLength(pStack, 0), getStackLength(pStack, 1), getStackSize(pStack));
    char tmp = 'a';
    printf("\nTrying to get an elem from empty stack0...    status: %d   ", getElem(pStack, &tmp, 0));
    printf("tmp initially equal \'a\', now is \'%c\'\n", tmp);

    tmp = 'a';
    printf("\nTrying to pop an elem from empty stack1...    status: %d   ", popElem(pStack, &tmp, 1));
    printf("tmp initially equal \'a\', now is \'%c\'\n", tmp);

    printf("\nPush test: %s\n", str);
    int i = 0;
    for (i = 0; i < strlen(str); i++)
        printf("Pushing %d: \'%c\'  Status: %d\n", i, str[i], pushElem(pStack, str[i], i%2));

    for (i = 0; i < 10; i++)
        printf("%d ", (pStack->pSpace)[i]);
    putchar('\n');

    for (i = 0; i < strlen(str); i++){
        printf("Poping %d:  Status: %d   ", i, popElem(pStack, &tmp, 1));
        printf("tmp: \'%c\'\n", tmp);
    }

    printf("\nclearStack Test, pushing %10s\n", str);
    for (i = 0; i < 10; i++)
        printf("Pushing %d: \'%c\'  Status: %d\n", i, str[i], pushElem(pStack, str[i], 1));
    printf("Stacklength: %d Size: %d isStackEmpty: %d\n", getStackLength(pStack, 1), getStackSize(pStack), isStackEmpty(pStack, 1));
    printf("Clearing Stack...\n");
    clearStack(pStack, 1);
    printf("Stack1length: %d Size: %d isStackEmpty: %d\n", getStackLength(pStack, 1), getStackSize(pStack), isStackEmpty(pStack, 1));
    printf("Stack0length: %d Size: %d isStackEmpty: %d\n", getStackLength(pStack, 0), getStackSize(pStack), isStackEmpty(pStack, 0));

    printf("\nfreeStack test, freeing...\n");
    freeStack(&pStack);
    printf("pStack: %p\n", pStack);

    return 0;
}