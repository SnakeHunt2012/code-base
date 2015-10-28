#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void visit(tree_link tree_node_ptr);

main(int argc, char *argv[])
{
    tree_link root = malloc(8 * sizeof *root);

    root[0].value = 'E';
    root[1].value = 'D';
    root[2].value = 'H';
    root[3].value = 'B';
    root[4].value = 'F';
    root[5].value = 'A';
    root[6].value = 'C';
    root[7].value = 'G';

    root[0].left = root + 1; root[0].right = root + 2;
    root[1].left = root + 3; root[1].right = NULL;
    root[2].left = root + 4; root[2].right = NULL;
    root[3].left = root + 5; root[3].right = root + 6;
    root[4].left = NULL; root[4].right = root + 7;
    root[5].left = NULL; root[5].right = NULL;
    root[6].left = NULL; root[6].right = NULL;
    root[7].left = NULL; root[7].right = NULL;

    printf("level-order traverse (non-recursive): ");
    level_order_traverse(root, visit);
    putchar('\n');
    
    printf("preorder traverse (non-recursive): ");
    pre_order_traverse(root, visit);
    putchar('\n');
    
    printf("preorder traverse (recursive): ");
    recursive_pre_order_traverse(root, visit);
    putchar('\n');
    
    printf("inorder traverse (recursive): ");
    recursive_in_order_traverse(root, visit);
    putchar('\n');
    
    printf("postorder traverse (recursive): ");
    recursive_post_order_traverse(root, visit);
    putchar('\n');
}

void visit(tree_link tree_node_ptr)
{
    printf("%3c", tree_node_ptr->value);
}
