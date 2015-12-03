#include <stdio.h>
#include <stdlib.h>

#define min(A, B) (A < B) ? A : B
#define MAX 10000

static int aux[MAX];

void merge(int data[], int left, int middle, int right)
{
    int i, j, k;
    for (i = middle + 1; i > left; --i)
        aux[i - 1] = data[i - 1];
    for (j = middle; j < right; ++j)
        aux[right + middle - j] = data[j + 1];
    for (k = left; k <= right; ++k)
        if (aux[i] < aux[j])
            data[k] = aux[i++];
        else
            data[k] = aux[j--];
}

void sort(int data[], int left, int right)
{
    int i, middle;
    for (middle = 1; middle <= right - left; middle *= 2)
        for (i = left; i <= right - middle; i += middle * 2)
            merge(data, i, i + middle - 1, min(i + middle * 2 - 1, right));
}

int main(int argc, char *argv[])
{
    int i, length = atoi(argv[1]);
    int *data = malloc(length * sizeof(*data));
    for (i = 0; i < length; ++i)
        data[i] = 10 * (1.0 * rand() / RAND_MAX);
    for (i = 0; i < length; ++i) printf("%3d", data[i]);
    putchar('\n');
    sort(data, 0, length - 1);
    for (i = 0; i < length; ++i) printf("%3d", data[i]);
    putchar('\n');
}
