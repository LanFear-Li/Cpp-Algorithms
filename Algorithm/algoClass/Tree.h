//
// Created by LanFear on 2021/4/22.
//

#ifndef ALGOCLASS_TREE_H
#define ALGOCLASS_TREE_H

#include "Util.h"

typedef int DataType;

/* binary tree structure */
struct linked_node;
typedef struct linked_node *p_linked_node;
struct linked_node {
    int data;
    p_linked_node left;
    p_linked_node right;
};
typedef struct linked_node *binary_tree;
typedef binary_tree *p_binary_tree;

// create null tree with a root linked_node which has no content
p_binary_tree create_null_tree();

// create a null linked_node which data is 0 and has no child linked_node
p_linked_node create_null_node();

// find the right place to insert a linked_node
void insert(p_binary_tree tree, int val);

// inorder tree walk: left child -> root -> right child
void inorder_tree_walk(p_linked_node node);

// preorder tree walk: root -> left child -> right child
void preorder_tree_walk(p_linked_node node);

// postorder tree walk: left child -> right child -> root
void postorder_tree_walk(p_linked_node node);

int get_tree_height(p_linked_node root, int height);

#endif //ALGOCLASS_TREE_H
