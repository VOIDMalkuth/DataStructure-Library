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
    pStack->count = 0;
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
    pStack->count = 0;
    return;
}

/* getStackLength: get current item count of the stack.
 * Argument: pointer to Stack.
 * Return Value: item count.
 */
#define getStackLength(X) ((X)->count) 

/* getStackSize: get current max size of the stack.
 * Argument: pointer to Stack.
 * Return Value: max size.
 */
#define getStackSize(X) ((X)->size)

/* isStackEmpty: check if the stack is empty.
 * Argument: pointer to Stack.
 * Return Value: 1 -- empty, 0 -- not empty.
 */
#define isStackEmpty(X) ((getStackLength(X) == 0) ? 1:0)

/* isStackFull: check if the stack is full.
 * Argument: pointer to Stack.
 * Return Value: 1 -- full, 0 -- not full.
 */
#define isStackFull(X) ((getStackLength(X) == getStackSize(X)) ? 1:0)

/* pushElem: push an element.
 * Argument: pStack -- pointer to stack,
 *           elem -- element.
 * Return: 0 -- success, -1 -- failure.
 */
int pushElem(Stack *pStack, elemType elem){
    if(isStackFull(pStack))
        return -1;

    (pStack->pSpace)[++(pStack->top)] = elem;
    (pStack->count)++;

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
        (pStack->count)--;
    }


    return status;
}