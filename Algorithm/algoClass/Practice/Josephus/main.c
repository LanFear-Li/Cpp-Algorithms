#include <stdio.h>
#include <stdlib.h>

/*
 * Josephus table question
 * solving with simple sequenceList or cycled-linkedList
 *
 * @author LanFear HoHai University
 * */

struct seqList {
    int maxn;
    int n;
    int *element;
};
typedef struct seqList *pSeqList;

pSeqList createNullList(int m) {
    pSeqList list = (pSeqList) malloc(sizeof(struct seqList));
    list->maxn = m;
    list->n = 0;
    list->element = (int *) malloc(sizeof(m * 4));
    return list;
}

int is_NullList(pSeqList list) {
    return list->n == 0;
}

int locate_seq(pSeqList list, int x) {
    if (list->n == 0) return -1;
    for (int i = 0; i < list->n; ++i) {
        if (list->element[i] == x) return i;
    }
    return -1;
}

int insert_seq(pSeqList list, int p, int x) {
    if (list->maxn == list->n) {
        printf("insert_seq::list overflow!\n");
        return 0;
    } else if (p < 0 || p >= list->maxn) {
        printf("insert_seq::given place is illegal!\n");
        return 0;
    }
    if (p < list->n) {
        for (int i = list->n - 1; i >= p; --i)
            list->element[i + 1] = list->element[i];
        list->element[p] = x;
        list->n++;
        return 1;
    } else {
        list->element[list->n] = x;
        list->n++;
        return 1;
    }
}

void showList_seq(pSeqList list) {
    if (list->n == 0) {
        printf("showList_seq::nothing to show!\n");
    } else {
        for (int i = 0; i < list->n; ++i) {
            printf("%d\t", list->element[i]);
        }
        printf("\n");
    }
}

int deleteP_seq(pSeqList list, int index) {
    if (list->n == 0) {
        printf("deleteP_seq::list underflow!\n");
        return 0;
    } else if (index < 0 || index >= list->n) {
        printf("deleteP_seq::given place is illegal!\n");
        return 0;
    }
    for (int i = index; i < list->n - 1; ++i) {
        list->element[i] = list->element[i + 1];
    }
    list->n--;
    return 1;
}

/* s means start at the s-th person
 * m means end at the (s + m - 1)th person to leave */
void Josephus(pSeqList list, int s, int m) {
    /* element array ranges between [0, n) */
    int start = s - 1, count = m;
    while (list->n) {
        int out_index = (start + count - 1) % list->n;
        printf("out element is => %d\n", list->element[out_index]);
        deleteP_seq(list, out_index);
        start = out_index;
    }
}

int main() {
    pSeqList list = createNullList(8);

    for (int i = 0; i < list->maxn; ++i)
        insert_seq(list, i, i + 1);

    Josephus(list, 1, 4);
    free(list->element);
    free(list);
    return 0;
}
