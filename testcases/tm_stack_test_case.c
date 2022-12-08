#include<tm_stack.h>
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
Stack *stack;
stack = createStack(&succ);
if(stack==false)
{
printf("Unable to create stack\n");
return 0;
}
pushOnStack(stack,&x1,&succ);
if(succ) printf("%d pushed on stack\n",x1);
else printf("Unable to push %d on stack\n",x1);

pushOnStack(stack,&x2,&succ);
if(succ) printf("%d pushed on stack\n",x2);
else printf("Unable to push %d on stack\n",x2);

pushOnStack(stack,&x3,&succ);
if(succ) printf("%d pushed on stack\n",x3);
else printf("Unable to push %d on stack\n",x3);

pushOnStack(stack,&x4,&succ);
if(succ) printf("%d pushed on stack\n",x4);
else printf("Unable to push %d on stack\n",x4);

printf("Size of stack %d\n",getSizeOfStack(stack));
if(isStackEmpty(stack)) printf("stack is empty\n");
else printf("stack is not empty\n");
x=(int *)elementAtTopOfStack(stack,&succ);
printf("Element at top of stack is %d\n",*x);
printf("Now popping all elements from stack\n");
while(!isStackEmpty(stack))
{
x=(int *)popFromStack(stack,&succ);
printf("%d popped from stack\n",*x);
}
destroyStack(stack);
return 0;
}