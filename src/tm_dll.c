#ifndef TM_DLL_C
#define TM_DLL_C 123
#include<tm_dll.h>
#include<tm_common.h>
#include<stdlib.h>
DoublyLinkedList * createDoublyLinkedList(bool *success)
{
DoublyLinkedList *doublyLinkedList;
if(success) *success=false;
doublyLinkedList=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
if(doublyLinkedList==NULL) return NULL;
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
if(success) *success=true;
return doublyLinkedList;
}
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success)
{
DoublyLinkedListNode *doublyLinkedListNode;
if(success) *success=false;
if(doublyLinkedList==NULL) return;
doublyLinkedListNode=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(doublyLinkedListNode==NULL) return;
doublyLinkedListNode->ptr=ptr;
doublyLinkedListNode->next=NULL;
doublyLinkedListNode->previous=NULL;
if(doublyLinkedList->start==NULL)
{
doublyLinkedList->start=doublyLinkedListNode;
doublyLinkedList->end=doublyLinkedListNode;
doublyLinkedList->size++;
if(success) *success=true;
return;
}
doublyLinkedList->end->next=doublyLinkedListNode;
doublyLinkedListNode->previous=doublyLinkedList->end;
doublyLinkedList->end=doublyLinkedListNode;
doublyLinkedList->size++;
if(success) *success=true;
return;
}
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success)
{
DoublyLinkedListNode *doublyLinkedListNode,*p;
int x;
if(success) *success=false;
if(doublyLinkedList==NULL) return;
if(index<0 || index>doublyLinkedList->size) return;
doublyLinkedListNode=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(doublyLinkedListNode==false) return;
doublyLinkedListNode->next=NULL;
doublyLinkedListNode->previous=NULL;
doublyLinkedListNode->ptr=ptr;
for(x=0,p=doublyLinkedList->start;x<index;x++,p=p->next);
if(p=doublyLinkedList->start)
{
doublyLinkedList->start=doublyLinkedListNode;
doublyLinkedList->end=doublyLinkedListNode;
doublyLinkedList->size++;
if(success) *success=true;
return;
}
if(p=doublyLinkedList->end)
{
doublyLinkedList->end->next=doublyLinkedListNode;
doublyLinkedListNode->previous=doublyLinkedList->end;
doublyLinkedList->end=doublyLinkedListNode;
doublyLinkedList->size++;
if(success) *success=true;
return;
}
doublyLinkedListNode->next=p;
doublyLinkedListNode->previous=p->previous;
p->previous->next=doublyLinkedListNode;
p->previous=doublyLinkedListNode;
doublyLinkedList->size++;
if(success) *success=true;
return;
}
void *removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *p;
void *ptr;
int x;
if(success) *success=false;
if(doublyLinkedList==NULL || doublyLinkedList->start==NULL ) return NULL;
if(index<0 || index>=doublyLinkedList->size) return NULL;
for(x=0,p=doublyLinkedList->start;x<index;x++,p=p->next);
ptr=p->ptr;
if(doublyLinkedList->start==doublyLinkedList->end)
{
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
}else if(p==doublyLinkedList->start)
{
doublyLinkedList->start=p->next;
p->next->previous=NULL;
}else if(p==doublyLinkedList->end)
{
doublyLinkedList->end=p->previous;
p->previous->next=NULL;
}else
{
p->previous->next=p->next;
p->next->previous=p->previous;
}
doublyLinkedList->size--;
if(success) *success=true;
free(p);
return ptr;
}
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
DoublyLinkedListNode *node;
if(doublyLinkedList==NULL) return;
while(doublyLinkedList->start!=NULL)
{
node=doublyLinkedList->start;
doublyLinkedList->start=doublyLinkedList->start->next;
if(doublyLinkedList->start==NULL) doublyLinkedList->end=NULL;
node->previous=NULL;
free(node);
}
doublyLinkedList->size=0;
}
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
return doublyLinkedList->size;
}
void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success)
{

}
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL) return;
clearDoublyLinkedList(doublyLinkedList);
free(doublyLinkedList);
}
void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
}
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListIterator doublyLinkedListIterator;
if(success) *success=false;
doublyLinkedListIterator.node=NULL;
if(doublyLinkedList==NULL) return doublyLinkedListIterator;
if(doublyLinkedList->start==NULL)
{
if(success) *success=true;
return doublyLinkedListIterator;
}
doublyLinkedListIterator.node=doublyLinkedList->start;
if(success) *success=true;
return doublyLinkedListIterator;
}
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator)
{
if(doublyLinkedListIterator==NULL) return false;
else if(doublyLinkedListIterator->node==NULL) return false;
return true;
}
void *getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success)
{
void *ptr;
if(success) *success=false;
if(doublyLinkedListIterator==NULL  || doublyLinkedListIterator->node==NULL) return NULL;
ptr=doublyLinkedListIterator->node->ptr;
doublyLinkedListIterator->node=doublyLinkedListIterator->node->next;
if(success) *success=true;
return ptr;
}
#endif