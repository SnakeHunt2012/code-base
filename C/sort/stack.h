#ifndef STACK_H
#define STACK_H

typedef struct stack_node *stack_link;
struct stack_node {
    int value;
    stack_link next;
};

int stack_empty();
void stack_push(int value);
int stack_pop();

#endif
