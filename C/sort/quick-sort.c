#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

/* partition */
int partition(Item data[], int left, int right)
{
    int i = left - 1, j = right; Item value = data[right];
    for (;;) {
        while (less(data[++i], value)) ;
        while (less(value, data[--j])) if (j == left) break;
        if (i >= j) break;
        exch(data[i], data[j]);
    }
    exch(data[i], data[right]);
    return i;
}

/* quicksort */
void quicksort(Item data[], int left, int right)
{
    int i;
    if (right <= left) return;
    i = partition(data, left, right);
    quicksort(data, left, i - 1);
    quicksort(data, i + 1, right);
}

void sort(Item data[], int left, int right)
{
    quicksort(data, left, right);
}

main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]);
    int *data = malloc(N * sizeof(int));
    for (i = 0; i < N; ++i)
        data[i] = 10 * (1.0 * rand() / RAND_MAX);
    for (i = 0; i < N; ++i) printf("%3d", data[i]);
    putchar('\n');
    sort(data, 0, N - 1);
    for (i = 0; i < N; ++i) printf("%3d", data[i]);
    putchar('\n');
    return 0;
}
