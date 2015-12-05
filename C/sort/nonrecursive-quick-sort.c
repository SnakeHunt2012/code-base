#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { int t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define push(A, B) stack_push(B); stack_push(A);

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

int quicksort(int data[], int left, int right)
{
    int i;
    stack_init();
    push(left, right);
    while (!stack_empty()) {
        left = stack_pop(); right = stack_pop();
        if (right <= left) continue;
        i = partition(data, left, right);
        if (i - left > right - i) {
            push(left, i - 1);
            push(i + 1, right);
        }  else {
            push(i + 1, right);
            push(left, i - 1);
        }
    }
}

void sort(int data[], int left, int right)
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

