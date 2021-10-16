#include<stdio.h>
#include<conio.h>
# define n 5
void insf(int[],int,int *,int *);
void insr(int[],int,int *,int *);
int delf(int[],int,int *,int *);
int delr(int[],int,int *,int *);
void display();
int queue[n],front=-1,rear=-1;
void main()
{
clrscr();
int choice,value,data,i;
char ans;
do
{
printf("\nEnter your choice\n");
printf("1.Insert by front\n");
printf("2.Insert by rear\n");
printf("3.Delete by front\n");
printf("4.Delete by rear\n");
printf("5.Display\n");
scanf("%d",&choice);
switch(choice)
{

case 1:
printf("Enter the element to be inserted\n");
scanf("%d",&value);
insf(queue,value,&front,&rear);
break;

case 2:
printf("Enter the element to be inserted\n");
scanf("%d",&value);
insr(queue,value,&front,&rear);
break;

case 3:
value=delf(queue,data,&front,&rear);
printf("Deleted element is %d\n",value);
break;

case 4:
value=delr(queue,data,&front,&rear);
printf("Deleted element is %d\n",value);
break;

case 5:
display();
break;

default:
printf("Invalid Choice\n");

}

printf("\nDo you want to continue?\n");
ans=getche();
printf("\n");
}

while(ans=='Y' || ans=='y');
getch();
}

void insr(int q[],int item,int *front,int *rear)
{
if(*rear>=n-1)
{
printf("Overflow\n");
return;
}
if(*front==-1)
{
*front=0;
*rear=0;
q[*rear]=item;
return;
}
else
{
*rear=*rear+1;
q[*rear]=item;
return;
}
}

void insf(int q[],int item,int *front,int *rear)
{
if(*rear>=n-1)
{
printf("Overflow\n");
return;
}
if(*front==-1)
{
*front=0;
*rear=0;
q[*front]=item;
return;
}
else
{
int i;
i=*rear;
while(i>=0)
{
q[i+1]=q[i];
i--;
}
q[i+1]=item;
*rear=*rear+1;
return;
}
}


int delf(int q[],int d,int *front,int *rear)
{
if(*front==-1||*front>*rear)
{
printf("Underflow\n");
d=-1;
return d;
}
if(*front<*rear)
{
*front=*front+1;
d= q[*front-1];
return d;
}
else
{
d= q[*rear];
*front=-1;
*rear=-1;
return d;
}
}

int delr(int q[],int d,int *front,int *rear)
{
if(*front==-1||*front>*rear)
{
printf("Underflow\n");
d=-1;
return d;
}
d=q[*rear];
q[*rear]=NULL;
*rear=*rear-1;
return d;
}

void display()
{
int i;
for(i=front;i<=rear;i++)
{
printf("%d\n",queue[i]);
}
}
