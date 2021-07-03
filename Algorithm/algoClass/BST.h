//
// Created by LanFear on 2021/6/29.
//

#ifndef ALGOCLASS_BST_H
#define ALGOCLASS_BST_H

#include "Util.h"
#include "Dic.h"

struct bs_node;
typedef struct bs_node *p_bs_node;
struct bs_node {
    key_type key;
    p_bs_node left, right;
};
typedef struct bs_node *bs_tree;
typedef bs_tree *p_bs_tree;

/* util */
int create_bin_search_tree(p_bs_tree tree, seq_dictionary *dic);

int search(p_bs_tree tree, key_type key, p_bs_node *p);

int insert(p_bs_tree tree, key_type key);

int delete(p_bs_tree tree, key_type key);

#endif //ALGOCLASS_BST_H
