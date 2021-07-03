//
// Created by LanFear on 2021/6/29.
//

#ifndef ALGOCLASS_DIC_H
#define ALGOCLASS_DIC_H

#include "Util.h"

typedef int key_type;
typedef int data_type;

typedef struct {
    key_type key;
    data_type value;
} dic_element;

typedef struct {
    int maxn;
    int n;
    dic_element *element;
} seq_dictionary;

/* basic dictionary operation */
seq_dictionary *create_empty_seq_dictionary(int size);

int seq_linear_search(seq_dictionary *dic, key_type key, int *pos);

int seq_binary_search(seq_dictionary *dic, key_type key, int *pos);

typedef struct {
    int m;
    dic_element *element;
} hash_dictionary;

/* hash table with linear search method */
hash_dictionary *create_empty_hash_dictionary(int size);

int get_linear_hash_code(hash_dictionary *dic, key_type key);

int hash_linear_search(hash_dictionary *dic, key_type key, int *pos);

int hash_linear_insert(hash_dictionary *dic, dic_element ele);

int hash_linear_delete(hash_dictionary *dic, key_type key);

struct linked_node;
typedef struct linked_node *p_linked_node;
struct linked_node {
    dic_element ele;
    p_linked_node next;
};
typedef struct linked_node *linked_list;

typedef struct {
    int table_size;
    linked_list *linked_list_array;
} hash_table;

/* hash table with zip of linked list method */
int get_link_hash_code(hash_table *table, key_type key);

p_linked_node hash_link_search(hash_table *table, key_type key);

#endif //ALGOCLASS_DIC_H
