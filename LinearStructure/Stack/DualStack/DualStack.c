/* Author: Void-Malkuth
 * Date: 2019.3.15
 */

#include <stdio.h>
#include <stdlib.h>
#include "DualStack.h"

//spec is a specifier to determine which stack to use
//0 for the one from start, 1 for the one from the end

/* initDualStack: Init a dualstack with max size specified by maxSize.
 * Argument: max size of stack.
 * Return Value: Pointer to struct Stack, NULL when failure.
 */
Stack *initDualStack(int maxSize){
    Stack *pStack = (Stack *)malloc(sizeof(Stack));
    if (pStack == NULL)
        return NULL;
    
    elemType *pSpace = (elemType *)malloc(sizeof(elemType) * maxSize);
    if (pSpace == NULL){
        free(pStack);
        return NULL;
    }

    pStack->pSpace = pSpace;
    pStack->top = -1;
    pStack->bottom = maxSize;
    pStack->size = maxSize;

    return pStack;
}

/* freeStack: delete a DualStack forever and set pStack to NULL.
 * Argument: pointer to pStack.
 */
void freeStack(Stack **ppStack){
    Stack *pStack = *ppStack;
    if((pStack == NULL) || (pStack->pSpace == NULL))
        return;
    
    free(pStack->pSpace);
    free(pStack);
    *ppStack = NULL;
    return;
}

/* clearStack: empty a stack.
 * Argument: pointer to Stack.
 * NOTE: Original Data will not be deleted but will be overwritten.
 */
void clearStack(Stack *pStack, int spec){
    if(spec)
        pStack->bottom = pStack->size;
    else
        pStack->top = -1;
    return;
}

/* getStackLength: get current item count of the stack.
 * Argument: pointer to Stack.
 * Return Value: item count.
 */
int getStackLength(Stack *pStack, int spec){
    if(spec)
        return ((pStack->size) - (pStack->bottom));
    else
        return (pStack->top + 1);
}

/* getStackSize: get current max size of the stack.
 * Argument: pointer to Stack.
 * Return Value: max size.
 */
int getStackSize(Stack *pStack){
    return (pStack->size);
}

/* isStackEmpty: check if the stack is empty.
 * Argument: pointer to Stack.
 * Return Value: 1 -- empty, 0 -- not empty.
 */
int isStackEmpty(Stack *pStack, int spec){
    if(spec)
        return (pStack->bottom == pStack->size ? 1 : 0);
    else
        return (pStack->top == -1 ? 1 : 0);
}

/* isStackFull: check if the stack is full.
 * Argument: pointer to Stack.
 * Return Value: 1 -- full, 0 -- not full.
 */
int isStackFull(Stack *pStack){
    if (pStack->bottom - 1 > pStack->top)
        return 0;
    return 1;
}

/* pushElem: push an element.
 * Argument: pStack -- pointer to stack,
 *           elem -- element.
 * Return: 0 -- success, -1 -- failure.
 */
int pushElem(Stack *pStack, elemType elem, int spec){
    if(isStackFull(pStack))
        return -1;

    if (spec)
        (pStack->pSpace)[--(pStack->bottom)] = elem;
    else
        (pStack->pSpace)[++(pStack->top)] = elem;

    return 0;
}

/* getElem: get an element at top but don't delete.
 * Argument: pStack -- pointer to stack,
 *           pItem -- pointer to where the element should be stored 
 * Return: 0 -- success, -1 -- failure.
 */
int getElem(Stack *pStack, elemType *pItem, int spec){
    if (isStackEmpty(pStack, spec))
        return -1;
    if (spec)
        *pItem = (pStack->pSpace)[(pStack->bottom)];
    else
        *pItem = (pStack->pSpace)[(pStack->top)]; 

    return 0;
}

/* popElem: get an element at top and delete.
 * Argument: pStack -- pointer to stack,
 *           pItem -- pointer to where the element should be stored 
 * Return: 0 -- success, -1 -- failure.
 */
int popElem(Stack *pStack, elemType *pItem, int spec){
    int status = getElem(pStack, pItem, spec);
    if (!status){
        if (spec)
            (pStack->bottom)++;
        else
            (pStack->top)--;
    }

    return status;
}