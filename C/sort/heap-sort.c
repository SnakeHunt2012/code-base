#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { int t = A; A = B; B = t; }

#define MAX 10000

static int heap[MAX];

void fix_down(int heap[], int i, int length)
{
    int j;
    while (2 * i <= length) {
        j = 2 * i;
        if (j < length && less(heap[j], heap[j + 1])) ++j;
        if (!less(heap[i], heap[j])) break;
        exch(heap[i], heap[j]);
        i = j;
    }
}

void sort(int data[], int left, int right)
{
    int i, length = right - left + 1, *heap = data + left - 1;
    for (i = length / 2; i > 0; --i)
        fix_down(heap, i, length);
    while (length > 1) {
        exch(heap[1], heap[length]);
        fix_down(heap, 1, --length);
    }
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
