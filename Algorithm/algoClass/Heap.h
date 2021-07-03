//
// Created by LanFear on 2021/7/3.
//

#ifndef ALGOCLASS_HEAP_H
#define ALGOCLASS_HEAP_H

#include "Util.h"

struct priority_queue {
    int maxn;
    int n;
    int *pq;
};
typedef struct priority_queue *p_priority_queue;

void add_heap(p_priority_queue queue, int x);

void delete_heap(p_priority_queue queue);

void delete_heap_by_shift(p_priority_queue queue);

#endif //ALGOCLASS_HEAP_H
