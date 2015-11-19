#include <stdio.h>
#include <stdlib.h>

#define V 100

typedef struct node *link;
struct node {
    int value;
    link next;
};

link NEW(int value, link next)
{
    link x = malloc(sizeof(*x));
    x->value = value;
    x->next = next;
    return x;
}

int main()
{
    int i, j;
    link adj[V];
    for (i = 0; i < V; ++i)
        adj[i] = NULL;
    while (scanf("%d %d\n", &i, &j) == 2) {
        adj[j] = NEW(i, adj[j]);
        adj[i] = NEW(j, adj[i]);
    }
}
