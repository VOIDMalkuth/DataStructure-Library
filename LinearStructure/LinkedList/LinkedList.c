/* Author: Void-Malkuth
 * Date: 2019.3.7
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/********************************************
 * Head* initList(void)
 * Function: Init a list.
 * Return Value: pointer to head node.
 */
Head* initList(void){
    Head *p = (Head *)(malloc(sizeof(Head)));
    p->count = 0;
    p->next = NULL;
    p->pEnd = NULL;
    return p;
}

/********************************************
 * void freeList(Head **ppHead)
 * Function: free list and its head.
 * Argument: pHead --- pointer to pHead (In order to set it to NULL).
 * 
 * NOTE: After this operation, pHead will be NULL.
 */
void freeList(Head **ppHead){
    Head *pHead = *ppHead;
    Node *pNode = pHead->next;
    Node *pCur = pNode->next;
    
    while (pCur != NULL){
        free(pNode);
        pNode = pCur;
        pCur = pCur->next;
    }
    free(pNode);
    free(pHead);
    *ppHead = NULL;

    return;
}

/********************************************
 * int getListLength(Head *pHead)
 * Function: get list length
 * Argument: pHead --- pointer to Head
 * Return Value: length of the list
 */
int getListLength(Head *pHead){
    return pHead->count;
}

/********************************************
 * elemType* getElemByIndex(Head *pHead, unsigned int index)
 * Function: get element by index, indices starts from 1
 * Argument: pHead --- pointer to Head
 *           index --- position of element
 * Return Value: pointer to element, NULL if index is larger than list length 
 */
elemType* getElemByIndex(Head *pHead, unsigned int index){
    if (index > getListLength(pHead) || index == 0)
        return NULL;

    Node *pCur = pHead->next;

    int i = 1;
    for (i = 1; i < index; i++){
        pCur = pCur->next;
    }

    return &(pCur->item);
}

/********************************************
 * int findElem(Head *pHead, elemType item , int (*pCmp)(const void *, const void *))
 * Function: find an element and return the index of the first match.
 * Argument: pHead --- pointer to Head.
 *           item --- item to find.
 *           int (*pCmp)(const void *, const void *) ---
 *                  pointer to compare function, returns 0 when equal.
 * Return Value: [index] -- success, -1 -- not found.
 */
int findElem(Head *pHead, elemType item, int (*pCmp)(const void *, const void *)){
    Node *pCur = pHead->next;
    int i = 1;

    while (pCur != NULL){
        if (!(*pCmp)(&(pCur->item), &item))
            return i;
        pCur = pCur->next;
        i++;
    }

    return -1;
}

/********************************************
 * int insertNode(Head *pHead, Node *pNode, unsigned int pos)
 * Function: insert a Node after pos, add count. 
 * Argument: pHead --- pointer to Head. 
 *           pNode --- Node to be inserted. 
 *           pos --- position to insert node after,
 *                   starting from 1, use 0 to insert at beginning. 
 * Retuen Value: 0 -- success, -1 -- fail. 
 */
int insertNode(Head *pHead, Node *pNode, unsigned int pos){
    if (getListLength(pHead) < pos)
        return -1;

    if(pos == 0){
        pNode->next = pHead->next;
        pHead->next = pNode;

        if(getListLength(pHead) == pos)
            (pHead->pEnd) = pNode;
        
        (pHead->count)++;
        return 0;
    }
    
    Node *pCur = pHead->next;
    int i;
    for (i = 0; i < pos - 1; i++)
        pCur = pCur->next;

    pNode->next = pCur->next;
    pCur->next = pNode;

    if (pos == getListLength(pHead))
        (pHead->pEnd) = pNode;

    (pHead->count)++;

    return 0;
}

/********************************************
 * int deleteNode(Head *pHead, unsigned int pos)
 * Function: delete node at pos, decrease count
 * Argument: pHead --- pointer to Head 
 *           pos --- position to delete, starting from 1
 * Retuen Value: 0 -- success, -1 -- fail
 */
int deleteNode(Head *pHead, unsigned int pos){
    if (pos > getListLength(pHead) || pos == 0)
        return -1;

    Node *pCur = pHead->next;
    if(pos == 1){
        pHead->next = pCur->next;
        free(pCur);

        if (pos == getListLength(pHead))
            (pHead->pEnd) = NULL;

        (pHead->count)--;
        return 0;
    }

    int i;
    for (i = 0; i < pos - 2; i++)
        pCur = pCur->next;
    Node *pPre = pCur;
    pCur = pCur->next;
    pPre->next = pCur->next;
    free(pCur);

    if (pos == getListLength(pHead))
        (pHead->pEnd) = pPre;

    (pHead->count)--;
    return 0;
}


/********************************************
 * int swapElem(Head *pHead, Node *pNode1, Node *pNode2)
 * Function: swap two elements specified by index1 and index2
 * Argument: pHead --- pointer to Head 
 *           index1/index2 --- index of nodes to be swaped
 */
int swapElem(Head *pHead, Node *pNode1, Node *pNode2){
    if ((pNode1 == NULL) || (pNode2 == NULL))
        return -1;
    if (pNode1 == pNode2)
        return 0;

    elemType *pItem1 = &(pNode1->item);
    elemType *pItem2 = &(pNode2->item);
    elemType tmp = *pItem1;
    *pItem1 = *pItem2;
    *pItem2 = tmp;
    return 0;
}

/********************************************
 * void traverseList(Head *pHead, void (*pfun)(elemType item))
 * Function: visit every node and apply function specified by pfun
 * Argument: pHead --- pointer to Head 
 *           void (*pfun)(elemType *) --- pointer to a function 
 *                   with an argument of pointer to element and returns nothing
 */
void traverseList(Head *pHead, void (*pfun)(elemType *)){
    Node *pCur = pHead->next;
    while (pCur != NULL){
        (*pfun)(&(pCur->item));
        pCur = pCur->next;
    }
    return;
}

/********************************************
 * void sortList(Head *pHead, int (*compareFun)(const void *, const void *))
 * Function: sort a list,smaller ones first;
 * Argument: pHead --- pointer to Head 
 *           int (*compareFun)(const void *, const void *) --- pointer to  
 *                   compare function, which return postive number if
 *                   1st arg is larger than 2nd
 */
void sortList(Head *pHead, int (*pCmp)(const void *, const void *)){
    Node *pNode1, *pNode2;
    for (pNode1 = pHead->next; pNode1 != NULL; pNode1 = pNode1->next){
        for (pNode2 = pNode1->next; pNode2 != NULL; pNode2 = pNode2->next){
            if((*pCmp)(&(pNode1->item), &(pNode2->item)) > 0){
                swapElem(pHead, pNode1, pNode2);
            }
        }
    }
    return;
}

/********************************************
 * int insertElem(Head *pHead, elemType elem)
 * Function: insert an element to first 
 * Argument: pHead --- pointer to Head 
 *           elem --- element
 * Return Value: -1 for failure, 0 for success
 */
int insertElem(Head *pHead, elemType elem){
    if(pHead == NULL)
        return -1;
        
    Node *pNode = (Node *)malloc(sizeof(Node));
    pNode->item = elem;
    insertNode(pHead, pNode, 0);
    return 0;
}
