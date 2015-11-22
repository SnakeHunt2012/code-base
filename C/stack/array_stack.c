#include <stdlib.h>
#include "stack.h"

static int *stack;
static int depth;

void stack_init(int max)
{
    stack = malloc(max * sizeof(*stack));
    depth = 0;
}

int stack_empty()
{
    return depth == 0;
}

void stack_push(int item)
{
    stack[depth++] = item;
}

int stack_pop()
{
    return stack[--depth];
}
