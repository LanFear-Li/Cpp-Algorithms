//
// Created by LanFear on 2021/6/27.
//

#include "Graph.h"

vex_node *first_vertex(graph_list G) {
    return &(G.vertices[0]);
}

vex_node *next_vertex(graph_list G, vex_node *vi) {
    int idx = 0;
    while (idx < G.vex_num && G.vertices[idx].vertex != vi->vertex)
        idx++;

    if (idx >= G.vex_num - 1) {
        printf("no next vertex found.\n");
        return NULL;
    }
    return &(G.vertices[idx + 1]);
}

vex_node *first_adjacent(graph_list G, vex_node *vi) {
    int idx = 0;
    while (idx < G.vex_num && G.vertices[idx].vertex != vi->vertex)
        idx++;

    if (idx == G.vex_num - 1) {
        printf("no vertex %c in list.\n", vi->vertex);
    }
    return &(G.vertices[idx]);
}

vex_node *next_adjacent(graph_list G, vex_node *vi, vex_node *vj) {
    int idx_vi = 0, idx_vj = 0;
    int cnt = 0;
    for (int i = 0; i < G.vex_num; ++i) {
        if (G.vertices[i].vertex == vi->vertex) {
            idx_vi = i;
            cnt++;
        }
        if (G.vertices[i].vertex == vj->vertex) {
            idx_vj = i;
            cnt++;
        }
        if (cnt == 2)
            break;
    }

    if (cnt < 2) {
        printf("lack in vertex.\n");
        return NULL;
    }

    while (G.vertices[idx_vi].list != NULL && G.vertices[idx_vi].list->adj_vex != idx_vj)
        G.vertices[idx_vi].list = G.vertices[idx_vi].list->next_edge;

    if (G.vertices[idx_vi].list != NULL && G.vertices[idx_vi].list->next_edge != NULL) {
        int idx = G.vertices[idx_vi].list->next_edge->adj_vex;
        return &(G.vertices[idx]);
    } else {
        printf("no next adjacent found.\n");
        return NULL;
    }
}

void depth_first_traversal(graph_list G) {
    vex_node *v = first_vertex(G);
    v->mark = 1;
    while (v) {
        if (!v->mark)
            depth_first_search(G, v);
        v = next_vertex(G, v);
    }
}

void depth_first_search(graph_list G, vex_node *v) {
    vex_node *vex = (vex_node *) malloc(sizeof(vex_node));
    printf("%c", v->vertex);
    vex->mark = 1;

    vex = first_adjacent(G, v);
    while (vex) {
        if (!vex->mark)
            depth_first_search(G, vex);
        vex = next_adjacent(G, v, vex);
    }
}

void depth_first_search_with_stack(graph_list G, vex_node *v) {
    vex_node *vex;
    int n = G.vex_num;
    p_seq_stack stack = create_empty_stack_seq(n);
    printf("start vertex: %c", v->vertex);
    v->mark = 1;

    push_seq(stack, v);
    vex = first_adjacent(G, v);

    while (!is_empty_stack_seq(stack)) {
        if (vex != NULL) {
            if (vex->mark == 1)
                vex = next_adjacent(G, top_seq(stack), vex);
            else {
                printf("%c", vex->vertex);
                vex->mark = 1;
                push_seq(stack, vex);
            }
        } else {
            vex = top_seq(stack);
            pop_seq(stack);
        }
    }
}

void breadth_first_search(graph_list G, vex_node *v) {
    vex_node *x, *y;
    p_seq_queue queue = create_empty_queue_seq(G.vex_num);
    v->mark = 1;
    printf("%c", v->vertex);
    enQueue_seq(queue, v);

    while (!is_empty_queue_seq(queue)) {
        x = frontQueue_seq(queue);
        deQueue_seq(queue);
        y = first_adjacent(G, x);

        while (y != NULL) {
            if (!y->mark) {
                y->mark = 1;
                printf("%c", y->vertex);
                enQueue_seq(queue, y);
            }
            y = next_adjacent(G, x, y);
        }
    }
}

void prim(graph_matrix *G, Edge *mst) {
    Edge edge;
    int vex_x, vex_y;
    int weight;

    for (int i = 0; i < G->n - 1; ++i) {
        mst[i].start_vex = 0, mst[i].end_vex = i + 1;
        mst[i].weight = G->edges[0][i + 1];
    }

    int min_idx, min_weight;
    for (int i = 0; i < G->n - 1; ++i) {
        min_weight = INT_MAX, min_idx = i;

        for (int j = i; j < G->n - 1; ++j) {
            if (mst[j].weight < min_weight) {
                min_idx = j;
                min_weight = mst[j].weight;
            }
        }

        edge = mst[min_idx];
        mst[min_idx] = mst[i];
        mst[i] = edge;

        vex_x = mst[i].end_vex;
        for (int j = i + 1; j < G->n - 1; ++j) {
            vex_y = mst[j].end_vex;
            weight = G->edges[vex_x][vex_y];

            if (weight < mst[j].weight) {
                mst[j].weight = weight;
                mst[j].start_vex = vex_x;
            }
        }
    }
}

void dijkstra(graph_matrix *G, Path *dist) {
    dist[0].length = 0, dist[0].pre_vex = 0;
    G->edges[0][0] = 1;

    for (int i = 0; i < G->n; ++i) {
        dist[i].length = G->edges[0][i];
        if (G->edges[0][i] != INT_MAX)
            dist[i].pre_vex = 0;
        else
            dist[i].pre_vex = -1;
    }

    int min_idx, min_weight;
    for (int i = 1; i < G->n; ++i) {
        min_idx = 0, min_weight = INT_MAX;
        for (int j = 1; j < G->n; ++j) {
            if (!G->edges[j][j] && dist[j].length < min_weight) {
                min_weight = dist[j].length;
                min_idx = j;
            }
        }

        if (!min_idx)
            break;

        G->edges[min_idx][min_idx] = 1;
        for (int j = 1; j < G->n; ++j) {
            if (G->edges[j][j])
                continue;

            if (dist[j].length > dist[min_idx].length + G->edges[min_idx][j]) {
                dist[j].length = dist[min_idx].length + G->edges[min_idx][j];
                dist[j].pre_vex = min_idx;
            }
        }
    }
}

void floyd(graph_matrix *G, Short_path *path) {
    for (int i = 0; i < G->n; ++i) {
        for (int j = 0; j < G->n; ++j) {
            if (G->edges[i][j] != INT_MAX)
                path->next_vex[i][j] = j;
            else
                path->next_vex[i][j] = -1;

            path->a[i][j] = G->edges[i][j];
        }
    }

    for (int k = 0; k < G->n; ++k) {
        for (int i = 0; i < G->n; ++i) {
            for (int j = 0; j < G->n; ++j) {
                if (path->a[i][k] >= INT_MAX || path->a[k][j] >= INT_MAX)
                    continue;

                if (path->a[i][j] > path->a[i][k] + path->a[k][j]) {
                    path->a[i][j] = path->a[i][k] + path->a[k][j];
                    path->next_vex[i][j] = path->next_vex[i][k];
                }
            }
        }
    }
}

void find_indegree(graph_list *G, int *indegree) {
    vex_node *v = first_vertex(*G);
    while (v != NULL) {
        edge_list list = v->list;
        while (list != NULL) {
            indegree[list->adj_vex]++;
            list = list->next_edge;
        }
        v = next_vertex(*G, v);
    }
}

int topological_sort(graph_list *G, int *topo) {
    int *indegree = (int *) malloc(sizeof(int) * G->vex_num);
    find_indegree(G, indegree);

    int top = -1, idx, vex_num = 0;
    for (int i = 0; i < G->vex_num; ++i) {
        if (!indegree[i]) {
            indegree[i] = top;
            top = i;
        }
    }

    edge_list list;
    while (top != -1) {
        idx = top;
        top = indegree[top];
        topo[vex_num++] = idx;
        list = G->vertices[idx].list;
        while (list != NULL) {
            int k = list->adj_vex;
            indegree[k]--;

            if (!indegree[k]) {
                indegree[k] = top;
                top = k;
            }

            list = list->next_edge;
        }
    }

    free(indegree);
    if (vex_num < G->vex_num) {
        printf("detected a cycle");
        return 0;
    }
    return 1;
}

/* stack */
p_seq_stack create_empty_stack_seq(int m) {
    p_seq_stack stack = (p_seq_stack) malloc(sizeof(struct seq_stack));
    if (stack != NULL) {
        stack->s = (data_type *) malloc(sizeof(data_type *) * m);
        if (stack->s) {
            stack->n = -1;
            stack->maxn = m;
            return stack;
        } else {
            free(stack);
        }
    }
    printf("create empty stack failed, space overflow.\n");
    return NULL;
}

int is_empty_stack_seq(p_seq_stack stack) {
    return stack->n == -1;
}

void push_seq(p_seq_stack stack, data_type x) {
    if (stack->n == stack->maxn - 1) {
        printf("stack overflow.\n");
    } else {
        stack->n += 1;
        stack->s[stack->n] = x;
    }
}

void pop_seq(p_seq_stack stack) {
    if (stack->n == -1) {
        printf("stack underflow.\n");
    } else {
        stack->n -= 1;
    }
}

data_type top_seq(p_seq_stack stack) {
    if (stack->n == -1) {
        printf("stack underflow.\n");
        return 0;
    } else {
        return stack->s[stack->n];
    }
}

/* queue */
p_seq_queue create_empty_queue_seq(int size) {
    p_seq_queue queue = (p_seq_queue) malloc(sizeof(struct seq_queue));
    if (queue != NULL) {
        queue->q = (data_type *) malloc(sizeof(data_type) * m);
        if (queue->q) {
            queue->head = 0;
            queue->tail = 0;
            queue->maxn = m;
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

void enQueue_seq(p_seq_queue queue, data_type x) {
    if (queue->head == (queue->tail + 1) % queue->maxn) {
        printf("Queue overflow!\n");
    } else {
        queue->q[queue->tail] = x;
        queue->tail += 1;
        queue->tail %= queue->maxn;
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

data_type frontQueue_seq(p_seq_queue queue) {
    return queue->q[queue->head];
}