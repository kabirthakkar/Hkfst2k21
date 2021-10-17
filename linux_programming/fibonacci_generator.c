#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int Fib_0=0;
int Fib_1=1;
void *Fibonacci_Generator(void * para)
{
char * ch=(char*)para;
int data=atoi(ch);
 bool isrun=true;
 int sum=0;
 printf("%d  %d",Fib_0,Fib_1);
 while(isrun)
 {
  if(data>sum)
  {
  sum=Fib_0+Fib_1;
  Fib_0=Fib_1;
  Fib_1=sum;
  printf("%d ",sum);
  }
  else
  isrun=false;
 } 
 Fib_0=0;
 Fib_1=1;
 pthread_exit(0);
}
int main(int argc,char * argv[])
{
if(argc<2)
{
printf("Usage: ./lab6 Numbers with\n");
return -1;
}
pthread_t *pt;
for(int i=0;i<argc-1;i++)
{
 printf("Thread %d :",i);
 pthread_create(&pt[i],NULL,&Fibonacci_Generator,argv[i+1]);
 pthread_join(pt[i],NULL);
}
return 0;
}
