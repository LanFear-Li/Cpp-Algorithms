//
// Created by LanFear on 2021/4/8.
//

#ifndef ALGOCLASS_STRING_H
#define ALGOCLASS_STRING_H

#include "Util.h"

struct seq_string {
    int maxn;
    int n;
    char *c;
};
typedef struct seq_string *p_seq_string;

p_seq_string create_null_string_seq(int size);

p_seq_string sub_string_seq(p_seq_string s, int i, int j);

int brutal_force_match(p_seq_string t, p_seq_string p);

int kmp_match(p_seq_string t, p_seq_string p);

struct string_node;
typedef struct string_node *p_string_node;

struct string_node {
    char c;
    p_string_node link;
};
typedef struct string_node *linked_string;

#endif //ALGOCLASS_STRING_H