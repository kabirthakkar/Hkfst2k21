#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct ll
{
int data;
struct ll *lptr;
struct ll *rptr;
}node;
node *first;
void insert(node *first,int x);
node* del(node *first);
void display(node *first);
void main()
{
clrscr();
int choice,item;
char ch;
first=NULL;
first->lptr=NULL;
first->rptr=NULL;
do
{
printf("\n");
printf("Enter your choice:\n");
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Display\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter the value to be inserted\n");
scanf("%d",&item);
insert(first,item);
printf("You inserted the value %d\n",item);
break;

case 2:
first=del(first);
break;

case 3:
node *temp;
temp=first;
if(first==NULL)
{
printf("Empty linked list\n");
}
else
{
while(temp->rptr!=NULL)
{
printf("%d ",temp->data);
temp=temp->rptr;
}
printf("%d ",temp->data);
}
break;

default:
printf("Invalid choice\n");
}

printf("\nDo you want to continue\n");
ch=getche();
}while(ch=='y'||ch=='Y') ;
getch();
}

void insert(node *,int x)
{
node *newn;
newn=(node*)malloc(sizeof(node));
newn->data=x;
if(first==NULL)
{
newn->lptr=NULL;
newn->rptr=NULL;
first=newn;
}
else
{
newn->lptr=NULL;
newn->rptr=first;
first=newn;
}
}

node* del(node *first)
{
int val;
if(first==NULL)
{
printf("Empty linked list\n");
return first;
}
else if(first->rptr==NULL&&first->lptr==NULL)
{
val=first->data;
first=NULL;
printf("You deleted %d\n",val);
return first;
}
else
{
node *temp;
temp=first;
node *pred;
while(temp->rptr!=NULL)
{
pred=temp;
temp=temp->rptr;
}
val=temp->data;
pred->rptr=NULL;
free(temp);
printf("You deleted %d\n",val);
return first;
}
}






