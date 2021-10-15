#include<stdio.h>
#include<conio.h>
void push1(int[],int *,int *,int);
void push2(int[],int *,int *,int);
int pop1(int[],int *,int *);
int pop2(int[],int *,int *);
void main()
{
clrscr();
int stack[10];
int top1=-1;
int top2=10;
int value,i,num,c,choice;
printf("Enter 1 to push\n");
printf("Enter 2 to pop\n");
printf("Enter 3 to display\n");
scanf("%d",&choice);

if(choice==1)
{
printf("Enter 1 to push from top1\n");
printf("Enter 2 to push from top2\n");
scanf("%d",&c);
if(c==1)
{
printf("Enter the number of values to be pushed\n");
scanf("%d",&num);
for(i=0;i<num;i++)
{
printf("Enter the value to be pushed\n");
scanf("%d",&value);
push1(stack,&top1,&top2,value);
}
printf("New Stack:\n");
if(num>10)
{
for(i=9;i>=0;i--)
{
printf("%d\n",stack[i]);
}
}
else
{
for(i=top1;i>=0;i--)
{
printf("%d\n",stack[i]);
}
}
}
if(c==2)
{
printf("Enter the number of values to be pushed\n");
scanf("%d",&num);
for(i=0;i<num;i++)
{
printf("Enter the value to be pushed\n");
scanf("%d",&value);
push2(stack,&top1,&top2,value);
}
printf("New Stack:\n");
if(num>10)
{
for(i=0;i<10;i++)
{
printf("%d\n",stack[i]);
}
}
else
{
for(i=top2;i<=9;i++)
{
printf("%d\n",stack[i]);
}
}
}
}
if(choice==2)
{
}
if(choice==3)
{
for(i=9;i>=0;i--)
{
printf("%d",stack[i]);
}
}
getch();
}
void push1(int s[],int * top1,int * top2,int val)
{
if(*top1+1==*top2)
{
printf("Overflow\n");
return;
}
*top1=*top1+1;
s[*top1]=val;
}
void push2(int s[],int * top1,int * top2,int val)
{
if(*top2-1==*top1)
{
printf("Overflow\n");
return;
}
*top2=*top2-1;
s[*top2]=val;
}






