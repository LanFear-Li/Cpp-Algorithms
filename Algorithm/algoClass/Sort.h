//
// Created by LanFear on 2021/6/26.
//

#ifndef ALGOCLASS_SORT_H
#define ALGOCLASS_SORT_H

#include "Util.h"

typedef int key_type;
typedef int data_type;
typedef struct {
    key_type key;
    data_type info;
} record_node;

typedef struct {
    int n;
    record_node *record;
} sort_object;


/* util */
sort_object *generate_random_object(int object_size);

void show_object(sort_object *object);

static inline void swap(record_node *record, int i, int j);

/* insert */
void direct_insert_sort(sort_object *p_vector);

void binary_insert_sort(sort_object *p_vector);

void shell_insert_sort(sort_object *p_vector, int d);


/* select */
void direct_select_sort(sort_object *p_vector);

void heap_select_sort(sort_object *p_vector);

/* swap */
void bubble_swap_sort(sort_object *p_vector);

void quick_swap_sort(sort_object *p_vector, int l, int r);

/* allocate */
void radix_sort();

/* merge */
void merge_sort(sort_object *p_vector);

#endif //ALGOCLASS_SORT_H
