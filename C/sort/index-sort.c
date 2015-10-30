#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (data[A] < data[B])
#define exch(A, B) { int t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

/* bubble sort */
void sort(int data[], int index[], int left, int right)
{
    int i, j;
    for (i = left; i < right; ++i)
        for (j = right; j > i; --j)
            compexch(index[j - 1], index[j]);
}

/* in-place sort */
void instu(int data[], int index[], int N)
{
    int i, j, k;
    for (i = 0; i < N; ++i) {
        int value = data[i];
        for (k = j = i; index[k] != i; k = index[k], index[j] = j) {
            j = k;
            data[k] = data[index[k]];
        }
        data[k] = value;
        index[k] = k;
    }
}

main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]);
    int *data = malloc(N * sizeof(int));
    int *index = malloc(N * sizeof(int));
    for (i = 0; i < N; ++i)
        data[i] = 10 * (1.0 * rand() / RAND_MAX);
    for (i = 0; i < N; ++i)
        index[i] = i;
    
    for (i = 0; i < N; ++i) printf("%3d", data[i]);
    putchar('\n');
    
    sort(data, index, 0, N - 1);
    
    for (i = 0; i < N; ++i) printf("%3d", data[i]);
    putchar('\n');
    
    for (i = 0; i < N; ++i) printf("%3d", index[i]);
    putchar('\n');
    
    for (i = 0; i < N; ++i) printf("%3d", data[index[i]]);
    putchar('\n');

    instu(data, index, N);
    
    for (i = 0; i < N; ++i) printf("%3d", data[i]);
    putchar('\n');
    
    return 0;
}
