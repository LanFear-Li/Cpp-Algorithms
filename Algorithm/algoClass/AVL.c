//
// Created by LanFear on 2021/6/29.
//

#include "AVL.h"

int avl_search(p_avl_tree tree, key_type key, p_avl_node *p) {
    p_avl_node node = *tree, temp = node;
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

int avl_insert(p_avl_tree tree, key_type key) {
    p_avl_node a, b, a_father;
    p_avl_node p, q;

    if (*tree == NULL) {
        *tree = create_avl_node(key);
        return 0;
    }

    a = p = *tree;
    a_father = q = NULL;

    while (p != NULL) {
        if (key == p->key) {
            printf("key already exist.\n");
            return 0;
        }

        q = p;

        if (key < p->key)
            p = p->left;
        else
            p = p->right;

        if (p->balance_factor) {
            a = p;
            a_father = q;
        }
    }

    p_avl_node node = create_avl_node(key);
    if (node == NULL)
        return 0;

    if (key < q->key)
        q->left = node;
    else
        q->right = node;

    int state;
    if (key < a->key) {
        p = b = a->left;
        state = -1;
    } else {
        p = b = a->right;
        state = 1;
    }

    while (p != node) {
        if (key < p->key) {
            p->balance_factor = -1;
            p = p->left;
        } else {
            p->balance_factor = 1;
            p = p->right;
        }
    }

    if (!a->balance_factor) {
        a->balance_factor = state;
        return 1;
    }
    if (a->balance_factor == -state) {
        a->balance_factor = 0;
        return 1;
    }

    if (state == -1) {
        if (b->balance_factor == -1)
            b = LL(a, b);
        else
            b = LR(a, b);
    } else {
        if (b->balance_factor == 1)
            b = RR(a, b);
        else
            b = RL(a, b);
    }

    if (a_father == NULL)
        *tree = b;
    else {
        if (a_father->left == a)
            a_father->left = b;
        else
            a_father->right = b;
    }
    return 1;
}

int avl_delete(p_avl_tree tree, key_type key);

p_avl_node create_avl_node(key_type key) {
    p_avl_node node = (p_avl_node) malloc(sizeof(struct avl_node));
    node->key = key;
    node->balance_factor = 0;
    node->left = node->right = NULL;
    return node;
}

p_avl_node LL(p_avl_node a, p_avl_node b) {
    a->balance_factor = 0;
    a->left = b->right;
    b->balance_factor = 0;
    b->right = a;
    return b;
}

p_avl_node RR(p_avl_node a, p_avl_node b) {
    a->balance_factor = 0;
    a->right = b->left;
    b->balance_factor = 0;
    b->left = a;
    return b;
}

p_avl_node LR(p_avl_node a, p_avl_node b) {
    p_avl_node c = b->right;
    a->left = c->right;
    b->right = c->left;
    c->left = b;
    c->right = a;

    switch (c->balance_factor) {
        case 0:
            a->balance_factor = 0, b->balance_factor = 0;
            break;
        case 1:
            a->balance_factor = 1, b->balance_factor = 0;
            break;
        case -1:
            a->balance_factor = 0, b->balance_factor = -1;
            break;
    }

    c->balance_factor = 0;
    return c;
}

p_avl_node RL(p_avl_node a, p_avl_node b) {
    p_avl_node c = b->left;
    a->right = c->left;
    b->left = c->right;
    c->left = a;
    c->right = b;

    switch (c->balance_factor) {
        case 0:
            a->balance_factor = 0, b->balance_factor = 0;
            break;
        case 1:
            a->balance_factor = 0, b->balance_factor = 1;
            break;
        case -1:
            a->balance_factor = -1, b->balance_factor = 0;
            break;
    }

    c->balance_factor = 0;
    return c;
}