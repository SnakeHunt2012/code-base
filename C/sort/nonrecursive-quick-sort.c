#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct stack_node *stack_link;
struct stack_node {
    Item value;
    stack_link next;
};

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define push(A, B) stack_push(B); stack_push(A);

static stack_link head = NULL;

int stack_empty(void)
{
    return head == NULL;
}

void stack_push(Item value)
{
    stack_link node_ptr = malloc(sizeof *node_ptr);
    node_ptr->value = value; node_ptr->next = head;
    head = node_ptr;
}

Item stack_pop(void)
{
    Item value;
    stack_link node_ptr = head;
    if (!head)
        return -1;
    value = head->value;
    head = head->next;
    free(node_ptr);
    return value;
}

int partition(Item data[], int left, int right)
{
    int i = left - 1, j = right; Item value = data[right];
    for (;;) {
        while (less(data[++i], value)) ;
        while (less(value, data[--j])) if (j == left) break;
        if (i >= j) break;
        exch(data[i], data[j]);
    }
    exch(data[i], data[right]);
    return i;
}

int quicksort(Item data[], int left, int right)
{
    int i;
    push(left, right);
    while (!stack_empty()) {
        left = stack_pop(); right = stack_pop();
        if (right <= left) continue;
        i = partition(data, left, right);
        if (i - left > right - i) {
            push(left, i - 1);
            push(i + 1, right);
        }  else {
            push(i + 1, right);
            push(left, i - 1);
        }
    }
}

void sort(Item data[], int left, int right)
{
    quicksort(data, left, right);
}

main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]);
    int *data = malloc(N * sizeof(int));
    for (i = 0; i < N; ++i)
        data[i] = 10 * (1.0 * rand() / RAND_MAX);
    for (i = 0; i < N; ++i) printf("%3d", data[i]);
    putchar('\n');
    sort(data, 0, N - 1);
    for (i = 0; i < N; ++i) printf("%3d", data[i]);
    putchar('\n');
    return 0;
}

