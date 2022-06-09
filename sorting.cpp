#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int data[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (data[j] > data[j + 1])
                swap(&data[j], &data[j + 1]);
}

void quickSort(int data[], int start, int end)
{

    int pivot, aux, i, j, center;

    i = start;
    j = end;

    center = (int)((i + j) / 2);
    pivot = data[center];

    do
    {
        while (data[i] < pivot)
            i = i + 1;
        while (data[j] > pivot)
            j = j - 1;

        if (i <= j)
        {
            aux = data[i];
            data[i] = data[j];
            data[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while (j > i);

    if (start < j)
        quickSort(data, start, j);
    if (i < end)
        quickSort(data, i, end);
}

int main()
{
    int data[] = {45, 7, 10, 4, 13, 17, 20, 16, 41, 21, 38, 43, 31, 2};
    int i, n = sizeof(data) / sizeof(data[0]);

    printf("\n");
    bubbleSort(data, n);
    printf("Bubble Sort: \n");
    for (i = 0; i < 14; i++)
        printf("%d ", data[i]);

    printf("\n");
    quickSort(data, 0, 13);
    printf("Quick Sort: \n");
    for (i = 0; i < 14; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
