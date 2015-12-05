#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_node *queue_link;
struct queue_node {
    void *value;
    queue_link next;
};

void queue_init();
int queue_empty();
void queue_put(void *value);
void *queue_get();

#endif
