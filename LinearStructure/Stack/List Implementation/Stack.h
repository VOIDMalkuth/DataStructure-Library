/* Author: Void-Malkuth
 * Date: 2019.3.13
 */
#include "LinkedList.h"

typedef char elemType;

typedef Head Stack;

Stack *initStack();

void freeStack(Stack **ppStack);

void clearStack(Stack *pStack);

/* getStackLength: get current item count of the stack.
 * Argument: pointer to Stack.
 * Return Value: item count.
 */
#define getStackLength(X) (getListLength(X))

int isStackEmpty(Stack *pStack);

int pushElem(Stack *pStack, elemType elem);

int getElem(Stack *pStack, elemType *pItem);

int popElem(Stack *pStack, elemType *pItem);