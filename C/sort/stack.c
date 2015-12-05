#include <stdlib.h>
#include "stack.h"

static stack_link head;

stack_link new_node(int value, stack_link next)
{
    stack_link node_ptr = malloc(sizeof *node_ptr);
    node_ptr->value = value; node_ptr->next = next;
    return node_ptr;
}

void stack_init()
{
    head = NULL;
}

int stack_empty(void)
{
    return head == NULL;
}

void stack_push(int value)
{
    head = new_node(value, head);
}

int stack_pop(void)
{
    int value;
    stack_link node_ptr = head;
    if (!head)
        return -1;
    value = head->value;
    head = head->next;
    free(node_ptr);
    return value;
}
