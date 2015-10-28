#ifndef QUEUE_H
#define QUEUE_H

#include "tree.h"

typedef struct queue_node *queue_link;
struct queue_node {
    tree_link value;
    queue_link next;
};

int queue_empty();
void queue_put(tree_link value);
tree_link queue_get();

#endif
