//
// Created by LanFear on 2021/4/8.
//

#include "Queue.h"

p_seq_queue create_empty_queue_seq(int size) {
    p_seq_queue queue = (p_seq_queue) malloc(sizeof(struct seq_queue));
    if (queue != NULL) {
        queue->q = (int *) malloc(sizeof(int) * size);
        if (queue->q) {
            queue->head = 0;
            queue->tail = 0;
            queue->maxn = size;
            return queue;
        } else {
            free(queue);
        }
    }
    printf("create empty queue failed, space overflow.\n");
    return NULL;
}

int is_empty_queue_seq(p_seq_queue queue) {
    return queue->head == queue->tail;
}

void enQueue_seq(p_seq_queue queue, int x) {
    if (queue->head == (queue->tail + 1) % queue->maxn) {
        printf("Queue overflow!\n");
    } else {
        queue->q[queue->tail] = x;
        queue->tail = (queue->tail + 1) % queue->maxn;
    }
}

void deQueue_seq(p_seq_queue queue) {
    if (queue->head == queue->tail) {
        printf("queue underflow.\n");
    } else {
        queue->head += 1;
        if (queue->head >= queue->maxn) {
            queue->tail -= queue->maxn;
        }
    }
}

int frontQueue_seq(p_seq_queue queue) {
    return queue->q[queue->head];
}

p_linked_queue create_empty_queue_link(int m) {
    p_linked_queue queue = (p_linked_queue) malloc(sizeof(struct linked_queue));
    if (queue != NULL) {
        queue->tail = NULL;
        queue->head = NULL;
    } else
        printf("malloc failed.\n");

    return queue;
}

int is_empty_queue_link(p_linked_queue queue) {
    return queue->head == NULL;
}

void enQueue_link(p_linked_queue queue, int x) {
    p_linked_node node = (p_linked_node) malloc(sizeof(struct linked_node));

    node->info = x;
    node->link = NULL;
    if (queue->head == NULL) {
        queue->head = node;
    } else
        queue->tail->link = node;

    queue->tail = node;
}

void deQueue_link(p_linked_queue queue) {
    p_linked_node node = queue->head;
    queue->head = queue->head->link;
    free(node);
}

int frontQueue_link(p_linked_queue queue) {
    if (is_empty_queue_link(queue))
        return queue->head->info;

    return -1;
}