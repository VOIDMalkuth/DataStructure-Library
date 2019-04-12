/* Author: Void-Malkuth
 * Date: 2019.3.13
 */

#include <stdio.h>
#include <string.h>
#include "Stack.h"

int main(void){
    char str[20] = "abcdefghijklmn";
    printf("Initing Stack...\n");
    Stack *pStack = initStack(10);
    printf("pStack: %p", pStack);
    printf("\nStacklength: %d Size: %d\n", getStackLength(pStack), getStackSize(pStack));
    char tmp = 'a';
    printf("\nTrying to get an elem from empty stack...    status: %d   ", getElem(pStack, &tmp));
    printf("tmp initially equal \'a\', now is \'%c\'\n", tmp);

    printf("\nTrying to pop an elem from empty stack...    status: %d   ", popElem(pStack, &tmp));
    printf("tmp initially equal \'a\', now is \'%c\'\n", tmp);

    printf("\nPush test: %s\n", str);
    int i = 0;
    for (i = 0; i < strlen(str); i++)
        printf("Pushing %d: \'%c\'  Status: %d\n", i, str[i], pushElem(pStack, str[i]));

    for (i = 0; i < strlen(str); i++){
        printf("Poping %d:  Status: %d   ", i, popElem(pStack, &tmp));
        printf("tmp: \'%c\'\n", tmp);
    }

    printf("\nclearStack Test, pushing %10s\n", str);
    for (i = 0; i < 10; i++)
        printf("Pushing %d: \'%c\'  Status: %d\n", i, str[i], pushElem(pStack, str[i]));
    printf("Stacklength: %d Size: %d isStackEmpty: %d\n", getStackLength(pStack), getStackSize(pStack), isStackEmpty(pStack));
    printf("Clearing Stack...\n");
    clearStack(pStack);
    printf("Stacklength: %d Size: %d isStackEmpty: %d\n", getStackLength(pStack), getStackSize(pStack), isStackEmpty(pStack));

    printf("\nfreeStack test, freeing...\n");
    freeStack(&pStack);
    printf("pStack: %p\n", pStack);

    return 0;
}