//
// Created by LanFear on 2021/6/29.
//

#ifndef ALGOCLASS_AVL_H
#define ALGOCLASS_AVL_H

#include "Util.h"
#include "Dic.h"

struct avl_node;
typedef struct avl_node *p_avl_node;
struct avl_node {
    key_type key;
    int balance_factor;
    p_avl_node left, right;
};
typedef struct avl_node *avl_tree;
typedef avl_tree *p_avl_tree;

/* util */
p_avl_node create_avl_node(key_type key);

p_avl_node LL(p_avl_node a, p_avl_node b);

p_avl_node LR(p_avl_node a, p_avl_node b);

p_avl_node RR(p_avl_node a, p_avl_node b);

p_avl_node RL(p_avl_node a, p_avl_node b);

int avl_search(p_avl_tree tree, key_type key, p_avl_node *p);

int avl_insert(p_avl_tree tree, key_type key);

int avl_delete(p_avl_tree tree, key_type key);

#endif //ALGOCLASS_AVL_H
