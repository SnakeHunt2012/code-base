#include <stdlib.h>
#include "stack.h"

typedef struct stack_node *link;
struct stack_node {
    int item;
    link next;
};

static link head;

link new_node(int item, link next)
{
    link x = malloc(sizeof(*x));
    x->item = item;
    x->next = next;
    return x;
}

void stack_init(int max)
{
    head = NULL;
}

int stack_empty()
{
    return head == NULL;
}

void stack_push(int item)
{
    head = new_node(item, head);
}

int stack_pop()
{
    int item = head->item;
    link x = head->next;
    free(head);
    head = x;
    return item;
}
