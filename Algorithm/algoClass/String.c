//
// Created by LanFear on 2021/4/8.
//

#include "String.h"

p_seq_string create_null_string_seq(int size) {
    p_seq_string seq_string = (p_seq_string) malloc(sizeof(struct seq_string));
    if (seq_string != NULL) {
        seq_string->c = (char *) malloc(sizeof(char) * size);
        seq_string->n = 0;
        seq_string->maxn = size;
        return seq_string;
    }

    printf("create null string failed: out of space.\n");
    return NULL;
}

p_seq_string sub_string_seq(p_seq_string s, int i, int j) {
    if (i >= j || i < 0 || j >= s->n) {
        printf("wrong index.\n");
        return NULL;
    }
    p_seq_string str = create_null_string_seq(s->maxn);
    for (int k = i; k <= j; k++) {
        str->c[k - i] = s->c[k];
    }
    str->n = j - i + 1;
    return str;
}

int brutal_force_match(p_seq_string t, p_seq_string p) {
    for (int i = 0; i <= t->n - p->n; ++i) {
        int flag = 1;
        for (int j = 0; j < p->n; ++j) {
            if (t->c[i + j] != p->c[j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) return i;
    }
    printf("match failed.\n");
    return -1;
}

/* getting the partial matching table / prefix table */
int *getIndex(p_seq_string p) {
    int *next = (int *) malloc(sizeof(int) * p->n);

    /*int i = 0, j = -1;
    next[0] = -1;
    while (i < p->n - 1) {
        while (j >= 0 && p->c[i] != p->c[j]) j = next[j];
        i++;
        k++;
        if (p->c[i] == p->c[j]) next[i] = next[j];
        else next[i] = j;
    }*/

    next[0] = -1;
    for (int i = 1, j = -1; i < p->n; ++i) {
        while (j != -1 && p->c[i] != p->c[j + 1]) j = next[j];
        if (p->c[i] == p->c[i + 1]) j++;
        next[i] = j;
    }

    return next;
}

/* matching pattern string p in template string t with KMP algorithm */
int kmp_match(p_seq_string t, p_seq_string p) {

    /*int *next = getIndex(p);
    int i = 0, j = 0;
    while (i < p->n && j < t->n) {
        if (i == -1 || p->c[i] == t->c[j]) {
            i++;
            j++;
        } else {
            i = next[i];
        }
    }
    if (i >= p->n) return j - p->n;*/

    int *next = getIndex(p);
    for (int i = 0, k = -1; i < t->n; ++i) {
        while (k != -1 && t->c[i] != p->c[k + 1]) k = next[k];
        if (t->c[i] == p->c[k + 1]) k++;
        if (k == p->n - 1) {
            printf("successfully find the index.\n");
            return (i - p->n + 1);
        }
    }
    printf("matching failed.\n");

    return 0;
}