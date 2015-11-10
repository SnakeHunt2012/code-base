#include <stdio.h>
#include <stdlib.h>

#define M 10
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { int t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

int partition(int data[], int left, int right)
{
    int i = left - 1, j = right; int value = data[right];
    for (;;) {
        while (less(data[++i], value)) ;
        while (less(value, data[--j])) if (j == left) break;
        if (i >= j) break;
        exch(data[i], data[j]);
    }
    exch(data[i], data[right]);
    return i;
}

void quicksort(int data[], int left, int right)
{
    int i;
    if (right - left <= M) return;
    exch(data[(left + right) / 2], data[right - 1]);
    compexch(data[left], data[right - 1]);
    compexch(data[left], data[right]);
    compexch(data[right - 1], data[right]);
    i = partition(data, left + 1, right - 1);
    quicksort(data, left, i - 1);
    quicksort(data, i + 1, right);
}

/* insertion sort */
void insertion(int data[], int left, int right)
{
    int i;
    for (i = right; i > left; --i) compexch(data[i - 1], data[i]);
    for (i = left + 2; i <= right; ++i) {
        int j = i; int value = data[i];
        while (less(value, data[j - 1])) {
            data[j] = data[j - 1];
            --j;
        }
        data[j] = value;
    }
}

void sort(int data[], int left, int right)
{
    quicksort(data, left, right);
    insertion(data, left, right);
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
