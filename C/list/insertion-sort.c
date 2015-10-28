#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
    int item;
    link next;
};

main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]);
    link input_index, input_head = malloc(sizeof *input_head), output_index, output_head = malloc(sizeof *output_head);

    /* initialize */
    input_index = input_head;
    for (i = 0; i < N; ++i) {
        input_index->next = malloc(sizeof *input_index);
        input_index->next->item = 10 * (1.0 * rand() / RAND_MAX);
        input_index = input_index->next;
    }
    input_index->next = NULL;

    /* print original list */
    for (input_index = input_head->next; input_index; input_index = input_index->next)
        printf("%3d", input_index->item);
    putchar('\n');

    /* sort */
    while (input_head->next) {
        input_index = input_head->next;
        input_head->next = input_index->next;
        for (output_index = output_head; output_index->next; output_index = output_index->next)
            if (output_index->next->item > input_index->item)
                break;
        input_index->next = output_index->next;
        output_index->next = input_index;
    }

    /* print sorted list */
    for (output_index = output_head->next; output_index; output_index = output_index->next)
        printf("%3d", output_index->item);
    putchar('\n');
}
