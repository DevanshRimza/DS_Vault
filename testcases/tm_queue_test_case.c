#include<tm_queue.h>
#include<stdio.h>
int main()
{
int succ;
int x1,x2,x3,x4;
int *x;
x1=10;
x2=20;
x3=30;
x4=40;
Queue *queue;
queue = createQueue(&succ);
if(queue==false)
{
printf("Unable to create queue\n");
return 0;
}
addToQueue(queue,&x1,&succ);
if(succ) printf("%d added on queue\n",x1);
else printf("Unable to add %d on queue\n",x1);

addToQueue(queue,&x2,&succ);
if(succ) printf("%d added on queue\n",x2);
else printf("Unable to add %d on queue\n",x2);

addToQueue(queue,&x3,&succ);
if(succ) printf("%d added on queue\n",x3);
else printf("Unable to add %d on queue\n",x3);

addToQueue(queue,&x4,&succ);
if(succ) printf("%d added on queue\n",x4);
else printf("Unable to add %d on queue\n",x4);

printf("Size of queue %d\n",getSizeOfQueue(queue));
if(isQueueEmpty(queue)) printf("queue is empty\n");
else printf("queue is not empty\n");
x=(int *)elementAtFrontOfQueue(queue,&succ);
printf("Element at front of queue is %d\n",*x);
printf("Now removing all elements from queue\n");
while(!isQueueEmpty(queue))
{
x=(int *)removeFromQueue(queue,&succ);
printf("%d removed from queue\n",*x);
}
destroyQueue(queue);
return 0;
}