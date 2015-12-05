#include <stdlib.h>
#include "queue.h"

static queue_link head, tail;

queue_link new_node(void *value, queue_link next)
{
    queue_link node_ptr = malloc(sizeof *node_ptr);
    node_ptr->value = value; node_ptr->next = next;
    return node_ptr;
}

void queue_init()
{
    head = NULL;
}

int queue_empty()
{
    return head == NULL;
}

void queue_put(void *value)
{
    if (queue_empty())
        head = tail = new_node(value, NULL);
    else
        tail = tail->next = new_node(value, NULL);
}

void *queue_get()
{
    void *value = head->value;
    queue_link node_ptr = head;
    head = head->next;
    free(node_ptr);
    return value;
}
