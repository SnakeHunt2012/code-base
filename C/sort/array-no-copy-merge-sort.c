#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { int t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

#define MAX 10000

static int aux[MAX];

void merge(int c[], int a[], int N, int b[], int M)
{
    int i, j, k;
    for (i = 0, j = 0, k = 0; k < M + N; ++k) {
        if (i == N) {
            c[k] = b[j++];
            continue;
        }
        if (i == M) {
            c[k] = a[i++];
            continue;
        }
        c[k] = (a[i] < b[j]) ? a[i++] : b[j++];
    }
}

void insertion_sort(int data[], int left, int right)
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

void merge_sort(int a[], int b[], int left, int right)
{
    int middle = (left + right) / 2;
    if (right - left <= 10) {
        insertion_sort(a, left, right);
        return;
    }
    merge_sort(b, a, left, middle);
    merge_sort(b, a, middle + 1, right);
    merge(a + left, b + left, middle - left + 1, b + middle + 1, right - middle);
}

void sort(int data[], int left, int right)
{
    int i;
    for (i = left; i <= right; ++i)
        aux[i] = data[i];
    merge_sort(data, aux, left, right);
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
