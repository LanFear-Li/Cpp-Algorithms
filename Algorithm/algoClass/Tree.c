//
// Created by LanFear on 2021/4/22.
//

#include "Tree.h"

p_binary_tree create_null_tree() {
    p_binary_tree tree = (p_binary_tree)malloc(sizeof (struct linked_node));
    *tree = NULL;
    return tree;
}

p_linked_node create_null_node() {
    p_linked_node node = (p_linked_node)malloc(sizeof (struct linked_node));
    node->data = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(p_binary_tree tree, int val) {
    p_linked_node node = create_null_node();
    p_linked_node x = *tree, y = NULL;
    node->data = val;
    while (x != NULL) {
        y = x;
        if (val < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    if (y == NULL) {
        *tree = node;
    } else if (val < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }
}

void inorder_tree_walk(p_linked_node node) {
    if (node != NULL) {
        inorder_tree_walk(node->left);
        printf("%d ", node->data);
        inorder_tree_walk(node->right);
    }
}

void preorder_tree_walk(p_linked_node node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder_tree_walk(node->left);
        preorder_tree_walk(node->right);
    }
}

void postorder_tree_walk(p_linked_node node) {
    if (node != NULL) {
        postorder_tree_walk(node->left);
        postorder_tree_walk(node->right);
        printf("%d ", node->data);
    }
}

int get_tree_height(p_linked_node root, int height) {
    if (root->left == NULL && root->right == NULL) {
        return height;
    }
    if (root->left) return get_tree_height(root->left, height + 1);
    if (root->right) return get_tree_height(root->right, height + 1);
    return 0;
}