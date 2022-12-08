#include<tm_avl_tree.h>
#include<stdio.h>
#include<stdlib.h>

int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}

int main()
{
AVLTreeInOrderIterator inOrderIterator;
AVLTreePreOrderIterator preOrderIterator;
AVLTreePostOrderIterator postOrderIterator;

int ch;
int *x;
int num;
AVLTree *tree;
int success;
tree=createAVLTree(&success,myComparator);
if(success==false)
{
printf("Unable to create tree,low on memory\n");
return 0;
}
while(1)
{
printf("1. Insert\n");
printf("2. In Order Traversal\n");
printf("3. Remove\n");
printf("4. Search\n");
printf("5. Pre Order Traversal\n");
printf("6. Post Order Traversal\n");
printf("7. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter number to be inserted in tree : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertIntoAVLTree(tree,(void *)x,&success);
if(success) printf("address of item that contain %d inserted in tree\n",*x);
else printf("Unable to insert in tree\n");
}

if(ch==2)
{
printf("In Order Iterator starts\n");
inOrderIterator=getAVLTreeInOrderIterator(tree,&success);
if(success)
{
while(hasNextInOrderElementInAVLTree(&inOrderIterator))
{
x=(int *)getNextInOrderElementFromAVLTree(&inOrderIterator,&success);
printf("%d\n",*x);
}
}
}

if(ch==3)
{
printf("Enter a number to Remove : ");
scanf("%d",&num);
fflush(stdin);
x=removeFromAVLTree(tree,&num,&success);
if(success) printf("%d found and removed\n",*x);
else printf("%d not found\n",num);
}

if(ch==4)
{
printf("Enter a number to search : ");
scanf("%d",&num);
fflush(stdin);
x=getFromAVLTree(tree,&num,&success);
if(success) printf("%d found\n",*x);
else printf("%d not found\n",num);
}

if(ch==5)
{
printf("Pre Order Iterator starts\n");
preOrderIterator=getAVLTreePreOrderIterator(tree,&success);
if(success)
{
while(hasNextPreOrderElementInAVLTree(&preOrderIterator))
{
x=(int *)getNextPreOrderElementFromAVLTree(&preOrderIterator,&success);
printf("%d\n",*x);
}
}
}

if(ch==6)
{
printf("Post Order Iterator starts\n");
postOrderIterator=getAVLTreePostOrderIterator(tree,&success);
if(success)
{
while(hasNextPostOrderElementInAVLTree(&postOrderIterator))
{
x=(int *)getNextPostOrderElementFromAVLTree(&postOrderIterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==7) break;
}
destroyAVLTree(tree);
return 0;
}