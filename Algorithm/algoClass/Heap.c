//
// Created by LanFear on 2021/7/3.
//

#include "Heap.h"

void add_heap(p_priority_queue queue, int x) {
    if (queue->n == queue->maxn - 1) {
        printf("queue overflow.\n");
        return;
    }

    int i;
    for (i = queue->n; i > 0 && queue->pq[(i - 1) / 2] > x; i = (i - 1) / 2)
        queue->pq[i] = queue->pq[(i - 1) / 2];

    queue->pq[i] = x;
    queue->n++;
}

void delete_heap(p_priority_queue queue) {
    int i = 0, child = 1, size = queue->n - 1;
    int temp_val = queue->pq[size];

    while (child < size) {
        if (child < size - 1 && queue->pq[child] > queue->pq[child + 1])
            child += 1;

        if (temp_val > queue->pq[child]) {
            queue->pq[i] = queue->pq[child];
            i = child;
            child = 2 * i + 1;
        } else
            break;
    }

    queue->pq[i] = temp_val;
}

void shift(p_priority_queue queue, int size, int pos) {
    int i = pos, child = 2 * i + 1;
    int temp_val = queue->pq[pos];

    while (child < size) {
        if (child < size - 1 && queue->pq[child] > queue->pq[child + 1])
            child += 1;

        if (temp_val > queue->pq[child]) {
            queue->pq[i] = queue->pq[child];
            i = child;
            child = 2 * i + 1;
        } else
            break;
    }

    queue->pq[i] = temp_val;
}

void delete_heap_by_shift(p_priority_queue queue) {
    int size = queue->n - 1;
    queue->pq[0] = queue->pq[size];
    shift(queue, size, 0);
}

