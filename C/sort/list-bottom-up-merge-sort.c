#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node *link;
struct node {
    int value;
    link next;
};

link merge(link a, link b)
{
    struct node head;
    link index = &head;
    while (a && b)
        if (a->value < b->value) {
            index->next = a;
            index = index->next;
            a = a->next;
        } else {
            index->next = b;
            index = index->next;
            b = b->next;
        }
    index->next = a ? a : b;
    return head.next;
}

link sort(link list)
{
    link node_ptr;
    for (queue_init(); list; list = node_ptr) {
        node_ptr = list->next;
        list->next = NULL;
        queue_put(list);
    }
    
    node_ptr = queue_get();
    while (!queue_empty()) {
        queue_put(node_ptr);
        node_ptr = merge(queue_get(), queue_get());
    }
    return node_ptr;
}

int main(int argc, char *argv[])
{
    int i, length = atoi(argv[1]);
    link index, list = malloc(length * sizeof(*list));

    /* initialize */
    for (i = 0; i < length; ++i) {
        list[i].value = 10 * (1.0 * rand() / RAND_MAX);
        list[i].next = (i == length - 1) ? NULL : &list[i + 1];
    }
    /* print original list */
    for (i = 0; i < length; ++i)
        printf("%3d", list[i].value);
    putchar('\n');

    list = sort(list);

    /* print sorted list */
    for (index = list; index; index = index->next)
        printf("%3d", index->value);
    putchar('\n');
}
