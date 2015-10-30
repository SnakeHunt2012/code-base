#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (*A < *B)
#define exch(A, B) { int *t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

/* bubble sort */
void sort(int *data[], int left, int right)
{
    int i, j;
    for (i = left; i < right; ++i)
        for (j = right; j > i; --j)
            compexch(data[j - 1], data[j]);
}

main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]);
    int *data = malloc(N * sizeof(int));
    int **address = malloc(N * sizeof(int *));
    for (i = 0; i < N; ++i)
        data[i] = 10 * (1.0 * rand() / RAND_MAX);
    for (i = 0; i < N; ++i)
        address[i] = &data[i];
    
    for (i = 0; i < N; ++i) printf("%3d", data[i]);
    putchar('\n');
    
    sort(address, 0, N - 1);
    
    for (i = 0; i < N; ++i) printf("%3d", data[i]);
    putchar('\n');
    
    for (i = 0; i < N; ++i) printf("%3d", *address[i]);
    putchar('\n');
    return 0;
}
