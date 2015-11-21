typedef struct queue_head *queue;

void queue_dump(queue);
queue queue_init(int);
int queue_empty(queue);
void queue_put(queue, int);
int queue_get(queue);
