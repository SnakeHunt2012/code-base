#include <stdio.h>

#define N 10
#define M 20
#define unknown -1

struct item {
    int size;
    int value;
};

int knap(int space, struct item *item_array, int *max_known, int *item_known)
{
    int i, size, value, max_item, max_value;
    if (max_known[space] != unknown)
        return max_known[space];
    for (i = 0, max_value = 0; i < N; ++i)
        if ((size = space - item_array[i].size) >= 0)
            if ((value = knap(size, item_array, max_known, item_known) + item_array[i].value) > max_value) {
                max_value = value;
                max_item = i;
            }
    max_known[space] = max_value;
    item_known[space] = max_item;
    return max_value;
}

int main()
{
    int i, max_known[M + 1], item_known[M + 1];
    struct item item_array[N];
    for (i = 0; i < N; ++i) {
        item_array[i].size = i + 1;
        item_array[i].value = i + 2;
    }
    for (i = 0; i <= M; ++i)
        max_known[i] = unknown;
    printf("knap(%d) = %d\n", M, knap(M, item_array, max_known, item_known));
    for (i = 0; i <= M; ++i)
        printf("%3d", max_known[i]);
    putchar('\n');
}
