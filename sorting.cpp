#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int vetor[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (vetor[j] > vetor[j + 1])
                swap(&vetor[j], &vetor[j + 1]);
}

void quickSort(int vetor[], int inicio, int fim)
{

    int pivo, aux, i, j, meio;

    i = inicio;
    j = fim;

    meio = (int)((i + j) / 2);
    pivo = vetor[meio];

    do
    {
        while (vetor[i] < pivo)
            i = i + 1;
        while (vetor[j] > pivo)
            j = j - 1;

        if (i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while (j > i);

    if (inicio < j)
        quickSort(vetor, inicio, j);
    if (i < fim)
        quickSort(vetor, i, fim);
}

int main()
{
    int vetor[] = {45, 7, 10, 4, 13, 17, 20, 16, 41, 21, 38, 43, 31, 2};
    int i, n = sizeof(vetor) / sizeof(vetor[0]);

    printf("\n");
    bubbleSort(vetor, n);
    printf("Bubble Sort: \n");
    for (i = 0; i < 14; i++)
        printf("%d ", vetor[i]);

    printf("\n");
    quickSort(vetor, 0, 13);
    printf("Quick Sort: \n");
    for (i = 0; i < 14; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
