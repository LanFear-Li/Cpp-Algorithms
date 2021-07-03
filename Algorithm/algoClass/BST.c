//
// Created by LanFear on 2021/6/29.
//

#include "BST.h"

int create_bin_search_tree(p_bs_tree tree, seq_dictionary *dic) {
    *tree = NULL;
    for (int i = 0; i < dic->n; ++i) {
        if (!insert(tree, dic->element[i].key))
            return 0;
    }
    return 1;
}

int search(p_bs_tree tree, key_type key, p_bs_node *p) {
    p_bs_node node = *tree, temp = node;
    while (node != NULL) {
        temp = node;
        if (key < node->key)
            node = node->left;
        else if (key > node->key)
            node = node->right;
        else {
            *p = node;
            return 1;
        }
    }

    *p = temp;
    return 0;
}

int insert(p_bs_tree tree, key_type key) {
    p_bs_node new_node = (p_bs_node) malloc(sizeof(struct bs_node));
    p_bs_node node;

    if (search(tree, key, &node)) {
        printf("this key already exist.\n");
        return 0;
    }

    new_node->key = key;
    new_node->left = new_node->right = NULL;

    if (node == NULL)
        *tree = new_node;
    else if (key < node->key)
        node->right = new_node;
    else
        node->left = new_node;
    return 1;
}

int delete(p_bs_tree tree, key_type key) {
    p_bs_node p, p_father, r;
    p = *tree, p_father = NULL;

    while (p != NULL) {
        if (key == p->key)
            break;

        p_father = p;
        if (key < p->key)
            p = p->left;
        else
            p = p->right;
    }

    if (p == NULL) {
        printf("this key not exist.\n");
        return 0;
    }

    if (p->left == NULL) {
        if (p_father == NULL)
            *tree = p->right;
        else if (p_father->left == p)
            p_father->left = p->right;
        else
            p_father->right = p->right;
    } else {
        r = p->left;
        while (r->right != NULL)
            r = r->right;

        r->right = p->right;
        if (p_father == NULL)
            *tree = p->left;
        else if (p_father->left == p)
            p_father->left = p->left;
        else
            p_father->right = p->left;
    }

    free(p);
    return 1;
}