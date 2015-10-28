#ifndef STACK_H
#define STACK_H

#include "tree.h"

typedef struct stack_node *stack_link;
struct stack_node {
    tree_link value;
    stack_link next;
};

int stack_empty();
void stack_push(tree_link value);
tree_link stack_pop();

#endif
