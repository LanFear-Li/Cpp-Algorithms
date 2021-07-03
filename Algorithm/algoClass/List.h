//
// Created by LanFear on 2021/4/8.
//

#ifndef ALGOCLASS_LIST_H
#define ALGOCLASS_LIST_H

#include "Util.h"

/* linear list:: type sequence */
struct seq_list {
    int maxn;
    int n;
    int *element;
};
typedef struct seq_list *p_seq_list;

p_seq_list create_null_list_seq(int m);

int is_null_list(p_seq_list list);

int locate_seq(p_seq_list list, int x);

int insert_pre_seq(p_seq_list list, int p, int x);

int insert_post_seq(p_seq_list list, int p, int x);

int deleteP_seq(p_seq_list list, int p);

void show_list_seq(p_seq_list list);

/* linear list:: type link */
struct linked_node;
typedef struct linked_node *p_linked_node;
struct linked_node {
    int info;
    p_linked_node link;
};
typedef struct linked_node *linked_list;

linked_list create_null_list_link();

p_linked_node locate_link(linked_list list, int x);

int insert_pre_link(linked_list list, p_linked_node p, int info);

int insert_post_link(linked_list list, p_linked_node p, int info);

/* linear list:: type link and cycled */
struct cycled_linked_node;
typedef struct cycled_linked_node *p_cycled_linked_node;
struct cycled_linked_node {
    int info;
    p_cycled_linked_node link;
};
typedef struct cycled_linked_node *cycled_linked_list;

cycled_linked_list create_null_list_cycled_link();

/* linear list:: type link and double */
struct double_linked_node;
typedef struct double_linked_node *p_double_linked_node;
struct double_linked_node {
    p_double_linked_node left, right;
    int info;
};

struct double_linked_list {
    p_double_linked_node head;
    p_double_linked_node rear;
};

void delete_p_double_link(struct double_linked_list list, p_double_linked_node p);

int insert_post_double_link(struct double_linked_list list, p_double_linked_node p, int info);

int insert_pre_double_link(struct double_linked_list list, p_double_linked_node p, int info);

/* linear list:: type link and double and cycled */
struct double_cycled_linked_node;
typedef struct double_cycled_linked_node *p_double_cycled_linked_node;
struct double_cycled_linked_node {
    int info;
    p_cycled_linked_node link;
};
typedef struct double_cycled_linked_node *double_cycled_linked_list;

double_cycled_linked_list convert_to_double_cycled_linked_list(cycled_linked_list list);

/* other operation */
int reverse_link(linked_list list);

void delete_duplicated_data_link(linked_list list);

int delete_all_data_link(linked_list list, int info);

#endif //ALGOCLASS_LIST_H
