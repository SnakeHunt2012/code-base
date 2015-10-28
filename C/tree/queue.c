#include <stdlib.h>
#include "queue.h"

static queue_link head = NULL;
static queue_link tail = NULL;

int queue_empty()
{
    return head == NULL;
}

void queue_put(tree_link value)
{
    if (head == NULL) {
        head = tail = malloc(sizeof *tail);
        tail->value = value; tail->next = NULL;
        return;
    }
    tail->next = malloc(sizeof *tail);
    tail->next->value = value; tail->next->next = NULL;
    tail = tail->next;
}

tree_link queue_get()
{
    tree_link value;
    queue_link node_ptr = head;
    if (!head)
        return NULL;
    value = node_ptr->value;
    head = head->next;
    free(node_ptr);
    return value;
}

