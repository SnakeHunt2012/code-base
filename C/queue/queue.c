#include <stdlib.h>
#include "queue.h"

typedef struct queue_node *link;

struct queue_head { link head; link tail; };
struct queue_node { int item; link next; };

link new_node(int item, link next)
{
    link x = malloc(sizeof(*x));
    x->item = item;
    x->next = next;
    return x;
}

queue queue_init(int max)
{
    queue q = malloc(sizeof(*q));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

int queue_empty(queue q)
{
    return q->head == NULL;
}

void queue_put(queue q, int item)
{
    if (q->head == NULL) {
        q->tail = new_node(item, NULL);
        q->head = q->tail;
    } else {
        q->tail->next = new_node(item, NULL);
        q->tail = q->tail->next;
    }
}

int queue_get(queue q)
{
    int item = q->head->item;
    link t = q->head;
    q->head = q->head->next;
    free(t);
    return item;
}

