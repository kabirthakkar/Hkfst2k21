//Himanshu Kumar
//https://github.com/HK24-HIMANSHU
#include<bits/stdc++.h>
using namespace std;
#define QSIZE 5
int f=-1,r=-1;

//function to push elements in the queue
void enqueue(int q[],int item){
    if(r==QSIZE-1)
        cout<<"Queue is full"<<endl;
    else{
        if((f==-1) &&(r==-1))
            f=r=0;
        else
            r++;
        q[r]=item;
    }
    return;
}

//function to remove elements from the queue
void dequeue(int q[]){
    int item;
    if((f==-1)&&(r==-1))
        cout<<"Queue is empty"<<endl;
    else{
        item=q[f];
        cout<<"The deleted item from queue is  "<<item<<endl;
        if(f==r)
            f=r=1;
        else
            f++;
    }
    return;
}

//function to display elements of the queue
//Time complexity=O(n)
void display(int q[]){
    int i;
    if((f==-1)&&(r==-1))
        cout<<"Queue is empty"<<endl;
    else{
        cout<<"Elements in queue are "<<endl;
        for(i=f;i<=r;i++)
            cout<<q[i]<<endl;
    }
    return;
}
int main(){
    int q[QSIZE],item,choice;
    do{
        cout<<"\n 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n";
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter item\n";
            cin>>item;
            enqueue(q,item);
            break;
            case 2: dequeue(q);
            break;
            case 3: display(q);
            break;
            case 4: exit(0);
            break;
        }
    }while(choice!=4);
}