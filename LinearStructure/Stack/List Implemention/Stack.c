/* Author: Void-Malkuth
 * Date: 2019.3.13
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Stack.h"

/* initStack: Init a stack
 * Return Value: Pointer to Stack, NULL when failure.
 */
Stack *initStack(){
    Stack *pStack = initList();
    return pStack;
}

/* freeStack: delete a Stack forever and set pStack to NULL.
 * Argument: pointer to pStack.
 */
void freeStack(Stack **ppStack){
    freeList(ppStack);
    return;
}

/* clearStack: empty a stack.
 * Argument: pointer to Stack.
 * NOTE: Original Data will not be deleted but will be overwritten.
 */
void clearStack(Stack *pStack){
    while(!deleteNode(pStack, 1))
        continue;
    return;
}


/* isStackEmpty: return whether a stack is empty
 */
int isStackEmpty(Stack *pStack){
    return ((getListLength(pStack) == 0) ? 1 : 0);
}

/* pushElem: push an element.
 * Argument: pStack -- pointer to stack,
 *           elem -- element.
 * Return: 0 -- success, -1 -- failure.
 */
int pushElem(Stack *pStack, elemType elem){
    return insertElem(pStack, elem);
}

/* getElem: get an element at top but don't delete.
 * Argument: pStack -- pointer to stack,
 *           pItem -- pointer to where the element should be stored 
 * Return: 0 -- success, -1 -- failure.
 */
int getElem(Stack *pStack, elemType *pItem){
    if(isStackEmpty(pStack))
        return -1;
    *pItem = *getElemByIndex(pStack, 1);

    return 0;
}

/* popElem: get an element at top and delete.
 * Argument: pStack -- pointer to stack,
 *           pItem -- pointer to where the element should be stored 
 * Return: 0 -- success, -1 -- failure.
 */
int popElem(Stack *pStack, elemType *pItem){
    int status = getElem(pStack, pItem);
    if(!status)
        deleteNode(pStack, 1);
    return status;
}