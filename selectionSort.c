//<<<<<<< main
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
void selection_Sort(int a[], int n)
{
	int i, j, iMin;
	for (j = 0; j < n-1; j++)
	{
		iMin = j;
		for (i = j+1; i < n; i++)
		{
			if (a[i] < a[iMin])
				iMin = i;
		}
		if (iMin != j)
			swap(j, iMin,a);
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
    selectionSort(A,n);
    printf("\nArray after sorting:");
    display(A,n);
}

//=======
#include <stdio.h>

void swap(int *input1, int *input2)
{
    int temp = *input1;
    *input1 = *input2;
    *input2 = temp;
}

void selection_Sort(int *array, const size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        int minPointer = i;

        for (int j = i; j < size; ++j)
            if (array[minPointer] > array[j])
                minPointer = j;
                
        swap(&array[minPointer], &array[i]);
    }
}

int main()
{
    int array[] = {3, 5, 1, 7, 10, 4, 9, 6, 8, 2};
    const size_t size = sizeof(array) / sizeof(array[0]);

    selectionSort(array, size);

    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
//>>>>>>> main
