#include <stdio.h>

#define N 30
#define unknown -1

int fibonacci(int i, int *known)
{
    int t;
    if (known[i] != unknown)
        return known[i];
    if (i == 0) t = 0;
    if (i == 1) t = 1;
    if (i > 1) t = fibonacci(i - 1, known) + fibonacci(i - 2, known);
    return known[i] = t;
}

int main()
{
    int i, known[N];
    for (i = 0; i < N; ++i)
        known[i] = unknown;
    for (i = 0; i < N; ++i)
        printf("fibonacci(%d) = %d\n", i, fibonacci(i, known));
}
