/* Author: Void-Malkuth
 * Date: 2019.3.7
 */

/* Linked List
 * Node:[elemType ,next]
 * Head:[count ,next, pEnd]
 * Head -> N1 -> N2 -> ... -> Nn -> NULL
 */

#define _LINKED_LIST

typedef int elemType;

typedef struct Node{
    elemType item;
    struct Node *next;
} Node;

typedef struct Head{
    int count;
    struct Node *next;
    struct Node *pEnd;
} Head;

Head *initList(void);

void freeList(Head **ppHead);

int getListLength(Head *pHead);

elemType *getElemByIndex(Head *pHead, unsigned int index);

int findElem(Head *pHead, elemType item, int (*pCmp)(const void *, const void *));

int insertNode(Head *pHead, Node *pNode, unsigned int pos);

int deleteNode(Head *pHead, unsigned int pos);

int swapElem(Head *pHead, Node *pNode1, Node *pNode2);

void traverseList(Head *pHead, void (*pfun)(elemType *));

void sortList(Head *pHead, int (*pCmp)(const void *, const void *));

int insertElem(Head *pHead, elemType elem);