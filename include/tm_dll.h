#ifndef TM_DLL_H
#define TM_DLL_H 123
#include<tm_common.h>
typedef struct __tm_dll_node
{
void *ptr;
struct __tm_dll_node *next;
struct __tm_dll_node *previous;
}DoublyLinkedListNode;
typedef struct __tm_dll
{
struct __tm_dll_node *start;
struct __tm_dll_node *end;
int size;
}DoublyLinkedList;
typedef struct __tm_dll_iterator
{
struct __tm_dll_node *node;
}DoublyLinkedListIterator;
DoublyLinkedList * createDoublyLinkedList(bool *success);
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success);
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success);
void *removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success);
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success);
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator);
void *getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success);
#endif