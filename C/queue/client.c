#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define M 10

int main(int argc, char *argv[])
{
    int i, j, N = atoi(argv[1]);
    queue queue_array[M];
    for (i = 0; i < M; ++i)
        queue_array[i] = queue_init(N);
    printf("here\n");
    for (i = 0; i < N; ++i)
        queue_put(queue_array[rand() % M], i);
    for (i = 0; i < N; ++i, putchar('\n'))
        while (!queue_empty(queue_array[i]))
            printf("%3d", queue_get(queue_array[i]));
}
