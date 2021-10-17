#include<stdio.h>
const int size=5; 
int front=-1,rear=-1;
void enqueue(int *cq)
{
    int ele;
    if(front==(rear+1)%size)
        printf("\n Queue is full!!");
    else{
    printf("\n Enter the element to be added:");
    scanf("%d",&ele);
    if(front==-1)
      {
          rear=0;
          front=0;
      } 
    else
        {
            rear=(rear+1)%size;
        }
        
            *(cq+rear)=ele;
            printf("\n The element %d is added!!\n",ele);
    }
}

void dequeue(int *cq)
{
    
    if(front==-1)
      printf("\n Underflow!!");
    else
    {
      printf("\n The element %d is Deleted!!\n",*(cq+front));
      if(rear==front)
        rear=front=-1;
      else
        front=(front+1)%size;
    }
}

void display(int *cq)
{
    int i,f=front;
    if(front==-1)
      printf("\n Queue is Empty!!\n");
    else
    {
        printf("\n Elements in the Queue:\n\nfront");
        for(i=front;i!=rear;i=(i+1)%size)
            printf("\n %d ",*(cq+i),front,rear);
        printf("\n %d \nrear\n",cq[rear]);
    }
}
void main()
{
    printf("\n Circular Queue\n --------------\n");
    int CQueue[5],input=0;
    while(input!=4)
    {
        printf("\n Queue Operations:\n 1.Add element(Enqueue)\n 2.Delete element(Dequeue)\n 3.Display\n 4.Quit\n");
        scanf("%d",&input);
        switch (input)
        {
         case 1: enqueue(CQueue);
                 display(CQueue);
                break;
         case 2: dequeue(CQueue);
                 display(CQueue);
                break;
         case 3: display(CQueue);
                break;
         case 4: printf("\n Quitting...!");
                break;
         default: printf("\n Wrong Choice...!!\n");
                break;
        }
    }
}