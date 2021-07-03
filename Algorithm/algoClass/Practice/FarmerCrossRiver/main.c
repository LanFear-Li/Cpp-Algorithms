/*
 * A simple queue-BFS program
 * Solving the farmer cross river problem
 *
 * @author LanFear, HoHai University
 */

#include <stdio.h>
#include <stdlib.h>

struct SeqQueue {
    int MAXNUM;
    int head, tail;
    int* q;
};
typedef struct SeqQueue* pSeqQueue;

pSeqQueue createEmptyQueue_seq(int size) {
    pSeqQueue queue = (pSeqQueue) malloc(sizeof(struct SeqQueue));
    if (queue != NULL) {
        queue->q = (int *)malloc(sizeof(int) * size);
        if (queue->q) {
            queue->head = 0;
            queue->tail = 0;
            queue->MAXNUM = size;
            return queue;
        } else {
            free(queue);
        }
    }
    printf("create empty queue failed, space overflow.\n");
    return NULL;
}

int isEmptyQueue_seq(pSeqQueue queue) {
    return queue->head == queue->tail;
}

void enQueue_seq(pSeqQueue queue, int x) {
    if (queue->head == (queue->tail + 1) % queue->MAXNUM) {
        printf("Queue overflow!\n");
    } else {
        queue->q[queue->tail] = x;
        queue->tail += 1;
        queue->tail %= queue->MAXNUM;
    }
}

void deQueue_seq(pSeqQueue queue) {
    if (queue->head == queue->tail) {
        printf("queue underflow.\n");
    } else {
        queue->head += 1;
        if (queue->head >= queue->MAXNUM) {
            queue->tail -= queue->MAXNUM;
        }
    }
}

int frontQueue_seq(pSeqQueue queue) {
    return queue->q[queue->head];
}

/* get state of ... 0 for South, 1 for North */
int farmer(int pos) { return (pos & 0x08) != 0; }

int cabbage(int pos) { return (pos & 0x04) != 0; }

int goat(int pos) { return (pos & 0x02) != 0; }

int wolf(int pos) { return (pos & 0x01) != 0; }

int check_safe(int pos) {
    if (goat(pos) == cabbage(pos) && goat(pos) != farmer(pos)) {
        return 0;
    }
    if (wolf(pos) == goat(pos) && wolf(pos) != farmer(pos)) {
        return 0;
    }
    return 1;
}

void solve_farmer_problem() {
    static int size = 16;
    int pos, next_pos;
    int route[size];

    pSeqQueue move_to = createEmptyQueue_seq(size);

    for (int i = 0; i < size; ++i)
        route[i] = -1;

    enQueue_seq(move_to, 0x00);
    while (!isEmptyQueue_seq(move_to) && route[15] == -1) {
        pos = frontQueue_seq(move_to);
        deQueue_seq(move_to);

        for (int movers = 1; movers <= 8; movers <<= 1) {
            if (farmer(pos) == ((pos & movers) != 0)) {
                next_pos = pos ^ (0x08 | movers);

                if (check_safe(next_pos) && route[next_pos] == -1) {
                    route[next_pos] = pos;
                    enQueue_seq(move_to, next_pos);
                }
            }
        }
    }

    if (route[15] != -1) {
        printf("the reversed path is: \n");

        for (pos = 15; pos >= 0; pos = route[pos]) {
            printf("the location is %d\n", pos);
            if (pos == 0) return;
        }
    } else {
        printf("no solution\n");
    }
}

int main() {
    solve_farmer_problem();
    return 0;
}
