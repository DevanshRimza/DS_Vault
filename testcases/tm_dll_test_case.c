#include<tm_dll.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int i1,i2,i3,i4,i5,i6,y;
int *x;
bool succ;
DoublyLinkedList *list1;
DoublyLinkedListIterator iter;
list1=createDoublyLinkedList(&succ);
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;
addToDoublyLinkedList(list1,(void *)&i1,&succ);
addToDoublyLinkedList(list1,(void *)&i2,&succ);
addToDoublyLinkedList(list1,(void *)&i3,&succ);
addToDoublyLinkedList(list1,(void *)&i4,&succ);
addToDoublyLinkedList(list1,(void *)&i5,&succ);
addToDoublyLinkedList(list1,(void *)&i6,&succ);
iter=getDoublyLinkedListIterator(list1,&succ);
if(succ)
{
while(hasNextInDoublyLinkedList(&iter))
{
x=(int *)getNextElementFromDoublyLinkedList(&iter,&succ);
printf("%d\n",*x);
}
}
destroyDoublyLinkedList(list1);
return 0;
}