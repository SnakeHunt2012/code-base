#include <stdlib.h>
#include "stack.h"

static stack_link head = NULL;

int stack_empty(void)
{
    return head == NULL;
}

void stack_push(tree_link value)
{
    stack_link node_ptr = malloc(sizeof *node_ptr);
    node_ptr->value = value; node_ptr->next = head;
    head = node_ptr;
}

tree_link stack_pop(void)
{
    tree_link value;
    stack_link node_ptr = head;
    if (!head)
        return NULL;
    value = head->value;
    head = head->next;
    free(node_ptr);
    return value;
}
