#include "tree.h"
#include "stack.h"
#include "queue.h"

/* level_order_traverse:  level-order traverse */
void level_order_traverse(tree_link root, void (*visit)(tree_link))
{
    tree_link node_ptr;
    if (root) queue_put(root);
    while (!queue_empty()) {
        node_ptr = queue_get();
        (*visit)(node_ptr);
        if (node_ptr->left) queue_put(node_ptr->left);
        if (node_ptr->right) queue_put(node_ptr->right);
    }
}

/* pre_order_traverse:  preorder traverse (non-recursive) */
void pre_order_traverse(tree_link root, void (*visit)(tree_link))
{
    tree_link node_ptr;
    if (root) stack_push(root);
    while (!stack_empty()) {
        (*visit)(node_ptr = stack_pop());
        if (node_ptr->right) stack_push(node_ptr->right);
        if (node_ptr->left) stack_push(node_ptr->left);
    }
}

/* recursive_pre_order_traverse:  preorder traverse (recursive) */
void recursive_pre_order_traverse(tree_link root, void (*visit)(tree_link))
{
    if (!root) return;
    (*visit)(root);
    recursive_pre_order_traverse(root->left, visit);
    recursive_pre_order_traverse(root->right, visit);
}

/* recursive_in_order_traverse:  inorder traverse (recursive) */
void recursive_in_order_traverse(tree_link root, void (*visit)(tree_link))
{
    if (!root) return;
    recursive_in_order_traverse(root->left, visit);
    (*visit)(root);
    recursive_in_order_traverse(root->right, visit);
}

/* recursive_post_order_traverse:  postorder traverse (recursive) */
void recursive_post_order_traverse(tree_link root, void (*visit)(tree_link))
{
    if (!root) return;
    recursive_post_order_traverse(root->left, visit);
    recursive_post_order_traverse(root->right, visit);
    (*visit)(root);
}
