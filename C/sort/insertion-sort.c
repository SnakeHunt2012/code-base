#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

/* insertion sort */
void sort(Item data[], int left, int right)
{
    int i;
    for (i = right; i > left; --i) compexch(data[i - 1], data[i]);
    for (i = left + 2; i <= right; ++i) {
        int j = i; Item value = data[i];
        while (less(value, data[j - 1])) {
            data[j] = data[j - 1];
            --j;
        }
        data[j] = value;
    }
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
