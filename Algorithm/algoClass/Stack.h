//
// Created by LanFear on 2021/4/8.
//

#ifndef ALGOCLASS_STACK_H
#define ALGOCLASS_STACK_H

#include "Util.h"
#include "String.h"

/* stack:: type sequence */
typedef int data_type;

struct seq_stack {
    int maxn;
    int n;
    data_type *s;
};
typedef struct seq_stack *p_seq_stack;

p_seq_stack create_empty_stack_seq(data_type m);

int is_empty_stack_seq(p_seq_stack stack);

void push_seq(p_seq_stack stack, data_type x);

void pop_seq(p_seq_stack stack);

data_type top_seq(p_seq_stack stack);

/* stack:: type link */
struct linked_node;
typedef struct linked_node *p_linked_node;

struct linked_node {
    int info;
    p_linked_node *link;
};

struct linked_stack {
    p_linked_node top;
};
typedef struct linked_stack *p_linked_stack;

p_linked_stack create_empty_stack_link();

int is_empty_stack_link(p_linked_stack stack);

void push_link(p_linked_stack stack, int x);

void pop_link(p_linked_stack stack);

int top_link(p_linked_stack stack);

/* shared seq stack */
struct shared_seq_stack {
    int maxn;
    int top[2];
    data_type *s;
};
typedef struct shared_seq_stack *p_shared_seq_stack;

p_shared_seq_stack create_empty_stack_shared_seq(int size);

int is_empty_stack_shared_seq(p_shared_seq_stack stack, int idx);

void push_shared_seq(p_shared_seq_stack stack, int x, int idx);

void pop_shared_seq(p_shared_seq_stack stack, int idx);

int top_shared_seq(p_shared_seq_stack stack, int idx);

/* other operation */
void digit_conversion(int num, int d);

int bracket_match(p_seq_string str);

#endif //ALGOCLASS_STACK_H
