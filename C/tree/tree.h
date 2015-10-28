#ifndef TREE_H
#define TREE_H

typedef struct tree_node *tree_link;
struct tree_node {
    char value;
    tree_link left;
    tree_link right;
};

void level_order_traverse(tree_link root, void (*visit)(tree_link));
void pre_order_traverse(tree_link root, void (*visit)(tree_link));
void recursive_pre_order_traverse(tree_link root, void (*visit)(tree_link));
void recursive_in_order_traverse(tree_link root, void (*visit)(tree_link));
void recursive_post_order_traverse(tree_link root, void (*visit)(tree_link));

#endif
