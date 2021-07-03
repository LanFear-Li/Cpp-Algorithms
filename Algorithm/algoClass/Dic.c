//
// Created by LanFear on 2021/6/29.
//

#include "Dic.h"

seq_dictionary *create_empty_seq_dictionary(int size) {
    seq_dictionary *dic = (seq_dictionary *) malloc(sizeof(seq_dictionary));
    if (dic == NULL) {
        printf("create empty dictionary failed,\n");
        return NULL;
    }

    dic->element = (dic_element *) malloc(sizeof(dic_element) * size);
    if (dic->element == NULL) {
        printf("create empty dic->element failed.\n");
        return NULL;
    }
    return dic;
}

int seq_linear_search(seq_dictionary *dic, key_type key, int *pos) {
    for (int i = 0; i < dic->n; ++i) {
        if (dic->element[i].key == key) {
            *pos = i;
            return 1;
        }
    }

    *pos = dic->n;
    return 0;
}

int seq_binary_search(seq_dictionary *dic, key_type key, int *pos) {
    int l = 0, r = dic->n - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;

        if (dic->element[mid].key == key) {
            *pos = mid;
            return 1;
        } else if (dic->element[mid].key > key) {
            r = mid - 1;
        } else
            l = mid + 1;
    }

    *pos = dic->n;
    return 0;
}

hash_dictionary *create_empty_hash_dictionary(int size) {
    hash_dictionary *dic = (hash_dictionary *) malloc(sizeof(hash_dictionary));
    if (dic == NULL) {
        printf("create empty dictionary failed,\n");
        return NULL;
    }

    dic->m = size;
    dic->element = (dic_element *) malloc(sizeof(dic_element) * size);
    if (dic->element == NULL) {
        printf("create empty dic->element failed.\n");
        free(dic);
        return NULL;
    }

    for (int i = 0; i < size; ++i)
        dic->element[0].key = 0;

    return dic;
}

int get_linear_hash_code(hash_dictionary *dic, key_type key) {
    return key % dic->m;
}

int hash_linear_search(hash_dictionary *dic, key_type key, int *pos) {
    int hash_code = get_linear_hash_code(dic, key);

    for (int i = 0; i < dic->m; ++i) {
        if (dic->element[hash_code].key == key) {
            *pos = hash_code;
            return 1;
        } else if (!dic->element[hash_code].key) {
            *pos = hash_code;
            return 0;
        }

        hash_code = (hash_code + 1) % dic->m;
    }

    /* failed m times, hash overflow */
    *pos = -1;
    return 0;
}

int hash_linear_insert(hash_dictionary *dic, dic_element ele) {
    int pos;
    if (hash_linear_search(dic, ele.key, &pos) == 1) {
        printf("this key already exist.\n");
    } else if (pos != -1) {
        dic->element[pos] = ele;
    } else return 0;
    return 1;

    /* another way */
    /*int hash_code = get_linear_hash_code(dic, ele.key);
    for (int i = 0; i < dic->m; ++i) {
        if (!dic->element[hash_code].key) {
            dic->element[hash_code] = ele;
            return 1;
        }

        hash_code = (hash_code + 1) % dic->m;
    }

    *//* failed m times, nowhere to insert *//*
    return 0;*/
}

int get_link_hash_code(hash_table *table, key_type key) {
    return key % table->table_size;
}

p_linked_node hash_link_search(hash_table *table, key_type key) {
    int hash_code = get_link_hash_code(table, key);
    linked_list list = table->linked_list_array[hash_code];

    p_linked_node p = list;
    while (p != NULL) {
        if (p->ele.key == key)
            return p;

        p = p->next;
    }

    printf("key not exist.\n");
    return NULL;
}