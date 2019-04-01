typedef int elemType;

typedef struct Node
{
    elemType item;
    struct Node *next;
    struct Node *prev;
} Node;

typedef Node Head;

Node *initList(void);

void freeList(Head **ppHead);

//Insert after pCur
int insertNodeAfter(Node *pNode, Node *pCur);

int insertElemAfter(elemType elem, Node *pCur);

int deleteNode(Node *pNode);

int swapElem(Node *pNode_1, Node *pNode_2);

void sortList(Head *pHead, int (*pCmp)(const void *, const void *));

int insertOrderly(elemType item, Head *pHead, int (*pCmp)(const void *, const void *));