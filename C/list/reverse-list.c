#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
    int item;
    link next;
};

link reverse(link original_list) {
    link reversed_list = NULL, index;
    while (original_list) {
        index = original_list;
        original_list = original_list->next;
        index->next = reversed_list;
        reversed_list = index;
    }
    return reversed_list;
}

main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]);
    link index, original_list = N > 0 ? malloc(N * sizeof *original_list) : NULL;

    /* initialize */
    for (i = 0; i < N; ++i) {
        original_list[i].item = 10 * (1.0 * rand() / RAND_MAX);
        original_list[i].next = i < N - 1 ? original_list + i + 1 : NULL;
    }

    /* print original list */
    for (index = original_list; index; index = index->next)
        printf("%3d", index->item);
    putchar('\n');

    /* print reversed list */
    for (index = reverse(original_list); index; index = index->next)
        printf("%3d", index->item);
    putchar('\n');
}
