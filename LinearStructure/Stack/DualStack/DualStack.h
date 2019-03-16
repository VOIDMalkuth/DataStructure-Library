/* Author: Void-Malkuth
 * Date: 2019.3.15
 */

typedef char elemType;

typedef struct Stack{
    elemType *pSpace;
    int top;
    int bottom;
    int size;
} Stack;

//spec is a specifier to determine which stack to use
//0 for the one from start, 1 for the one from the end

Stack *initDualStack(int maxSize);

void freeStack(Stack **ppStack);

void clearStack(Stack *pStack, int spec);

int getStackLength(Stack *pStack, int spec);

int getStackSize(Stack *pStack);

int isStackEmpty(Stack *pStack, int spec);

int isStackFull(Stack *pStack);

int pushElem(Stack *pStack, elemType elem, int spec);

int getElem(Stack *pStack, elemType *pItem, int spec);

int popElem(Stack *pStack, elemType *pItem, int spec);