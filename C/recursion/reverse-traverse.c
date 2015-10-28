#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
    int item;
    link next;
};

void visit(link index)
{
    printf("%3d", index->item);
}

void reverse_traverse(link list)
{
    if (!list)
        return;
    reverse_traverse(list->next);
    visit(list);
}

main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]);
    link index, list = N > 0 ? malloc(N * sizeof *list) : NULL;

    /* initialize */
    for (i = 0; i < N; ++i) {
        list[i].item = 10 * (1.0 * rand() / RAND_MAX);
        list[i].next = i < N - 1 ? list + i + 1 : NULL;
    }

    /* print list */
    for (index = list; index; index = index->next)
        printf("%3d", index->item);
    putchar('\n');

    reverse_traverse(list);
    putchar('\n');
}
