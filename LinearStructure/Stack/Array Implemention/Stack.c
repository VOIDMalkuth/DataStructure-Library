/* Author: Void-Malkuth
 * Date: 2019.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/* initStack: Init a stack with max size specified by maxSize.
 * Argument: max size of stack.
 * Return Value: Pointer to struct Stack, NULL when failure.
 */
Stack *initStack(int maxSize){
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
    pStack->size = maxSize;

    return pStack;
}

/* freeList: delete a List forever and set pStack to NULL.
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
void clearStack(Stack *pStack){
    pStack->top = -1;
    return;
}

/* pushElem: push an element.
 * Argument: pStack -- pointer to stack,
 *           elem -- element.
 * Return: 0 -- success, -1 -- failure.
 */
int pushElem(Stack *pStack, elemType elem){
    if(isStackFull(pStack))
        return -1;

    (pStack->pSpace)[++(pStack->top)] = elem;

    return 0;
}

/* getElem: get an element at top but don't delete.
 * Argument: pStack -- pointer to stack,
 *           pItem -- pointer to where the element should be stored 
 * Return: 0 -- success, -1 -- failure.
 */
int getElem(Stack *pStack, elemType *pItem){
    if (isStackEmpty(pStack))
        return -1;

    *pItem = (pStack->pSpace)[(pStack->top)];

    return 0;
}

/* popElem: get an element at top and delete.
 * Argument: pStack -- pointer to stack,
 *           pItem -- pointer to where the element should be stored 
 * Return: 0 -- success, -1 -- failure.
 */
int popElem(Stack *pStack, elemType *pItem){
    int status = getElem(pStack, pItem);
    if(!status){
        (pStack->top)--;
    }


    return status;
}