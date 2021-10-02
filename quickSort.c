#include <stdio.h>
#include <stdbool.h>

void swap(int *input1, int *input2)
{
    int temp = *input1;
    *input1 = *input2;
    *input2 = temp;
}

const int partition(int* array, const int low, const int high)
{
    int pvt = array[low];
    int i = low, j = high;

    do
    {
        while (array[i] <= pvt)
            ++i;
        while (array[j] > pvt)
            --j; 

        if (i < j)
            swap(&array[i], &array[j]);
    }
    while ( i < j);

    swap(&array[pvt], &array[j]);
    return j;
}

void quickSort(int *array, const int low, const int high)
{
    if (low >= high)
        return;
    
    int mid = partition(array, low, high);
    quickSort(array, low, mid);
    quickSort(array, mid + 1, high);


}

int main()
{

    int array[] = {3, 5, 1, 7, 10, 4, 9, 6, 8, 2};
    const size_t size = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, size);

    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
