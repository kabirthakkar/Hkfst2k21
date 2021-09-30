#include <stdio.h>

void swap(int *input1, int *input2)
{
    int temp = *input1;
    *input1 = *input2;
    *input2 = temp;
}

void selectionSort(int *array, const size_t size)
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
