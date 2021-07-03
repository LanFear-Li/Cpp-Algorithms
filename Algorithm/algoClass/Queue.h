//
// Created by LanFear on 2021/4/8.
//

#ifndef ALGOCLASS_QUEUE_H
#define ALGOCLASS_QUEUE_H

#include<stdio.h>
#include<stdlib.h>

/* queue:: type sequence */
struct seq_queue {
    int maxn;
    int head, tail;
    int *q;
};
typedef struct seq_queue *p_seq_queue;

p_seq_queue create_empty_queue_seq(int m);

int is_empty_queue_seq(p_seq_queue queue);

void enQueue_seq(p_seq_queue queue, int x);

void deQueue_seq(p_seq_queue queue);

int frontQueue_seq(p_seq_queue queue);

/* queue:: type link */
struct linked_node;
typedef struct linked_node *p_linked_node;
struct linked_node {
    int info;
    p_linked_node link;
};

struct linked_queue {
    p_linked_node head;
    p_linked_node tail;
};
typedef struct linked_queue *p_linked_queue;

p_linked_queue create_empty_queue_link(int m);

int is_empty_queue_link(p_linked_queue queue);

void enQueue_link(p_linked_queue queue, int x);

void deQueue_link(p_linked_queue queue);

int frontQueue_link(p_linked_queue queue);

#endif //ALGOCLASS_QUEUE_H
