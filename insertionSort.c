#include<stdio.h>
void input(int A[],int n)
{
    int i;
    printf("Enter %d number of elements: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
}
void display(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
}
void swap(int j,int iMin,int A[])
{
        int temp;
        temp=A[j];
        A[j]=A[iMin];
        A[iMin]=temp;
}
void insertionSort(int arr[],int n)
{
    int i,j;
    for(int i=1;i<n;i++)
     {
        int key=arr[i];
        int j= i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void main()
{
    int A[20],n;
    printf("\nEnter the size of the array:");
    scanf("%d",&n);
    input(A,n);
    printf("\nArray before sorting:");
    display(A,n);
    insertionSort(A,n);
    printf("\nArray after sorting:");
    display(A,n);
}
