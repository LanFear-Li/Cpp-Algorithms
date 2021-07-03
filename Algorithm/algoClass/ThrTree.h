//
// Created by LanFear on 2021/4/23.
//

#ifndef ALGOCLASS_THRTREE_H
#define ALGOCLASS_THRTREE_H

#include "Util.h"
#include "Tree.h"

/* inorder_make_thread binary tree structure */
struct thread_linked_node;
typedef struct thread_linked_node *p_thread_linked_node;
struct thread_linked_node {
    int info;
    p_thread_linked_node lLink, rLink;
    int lTag, rTag;
};
typedef struct thread_linked_node *thread_linked_tree;
typedef thread_linked_tree *p_thread_linked_tree;

p_thread_linked_tree create_null_tree_thread();

p_thread_linked_node create_null_node_thread();

void insert_thread(p_thread_linked_tree tree, int val);

void inorder_make_thread(thread_linked_tree tree);

void inorder_tree_walk_thread(thread_linked_tree tree);

p_thread_linked_node find_post_in_pre_order(p_thread_linked_node node);

/* util stack:: type sequence */
struct seq_stack {
    int maxn;
    int n;
    thread_linked_tree *s;
};
typedef struct seq_stack *p_seq_stack;

p_seq_stack create_empty_stack(int m);

int is_empty_stack(p_seq_stack stack);

void push(p_seq_stack stack, thread_linked_tree x);

void pop(p_seq_stack stack);

thread_linked_tree top(p_seq_stack stack);

#endif //ALGOCLASS_THRTREE_H
