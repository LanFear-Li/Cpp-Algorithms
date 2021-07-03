//
// Created by LanFear on 2021/6/27.
//

#ifndef ALGOCLASS_GRAPH_H
#define ALGOCLASS_GRAPH_H

#include "Util.h"

/* matrix */
typedef char vex_type;
typedef int adj_type;
typedef struct {
    int n;
    vex_type *vertices;
    adj_type **edges;
} graph_matrix;

/* adjacent list */
struct edge_node;
typedef struct edge_node *p_edge_node;
typedef struct edge_node *edge_list;
struct edge_node {
    int adj_vex;
    adj_type weight;
    p_edge_node next_edge;
};

typedef struct {
    vex_type vertex;
    int mark;
    edge_list list;
} vex_node;

typedef struct {
    int vex_num;
    vex_node *vertices;
} graph_list;

/* utility function */
void create_empty_graph_list();

vex_node *first_vertex(graph_list G);

vex_node *next_vertex(graph_list G, vex_node *vi);

vex_node *first_adjacent(graph_list G, vex_node *vi);

vex_node *next_adjacent(graph_list G, vex_node *vi, vex_node *vj);

/* traversal */
void depth_first_traversal(graph_list G);

void depth_first_search(graph_list G, vex_node *v);

void depth_first_search_with_stack(graph_list G, vex_node *v);

void breadth_first_search(graph_list G, vex_node *v);

/* minimum spanning tree */
typedef struct {
    int start_vex, end_vex;
    adj_type weight;
} Edge;

void prim(graph_matrix *G, Edge *mst);

void kruskal(graph_matrix *G, Edge edge);

/* shortest path */
typedef struct {
    adj_type length;
    int pre_vex;
} Path;

void dijkstra(graph_matrix *G, Path *dist);

typedef struct {
    adj_type **a;
    int **next_vex;
} Short_path;

void floyd(graph_matrix *G, Short_path *path);

/* topological sort */
int topological_sort(graph_list *G, int *topo);

/* critical path */

/* stack */
typedef vex_node *data_type;
struct seq_stack {
    int maxn;
    int n;
    data_type *s;
};
typedef struct seq_stack *p_seq_stack;

p_seq_stack create_empty_stack_seq(int m);

int is_empty_stack_seq(p_seq_stack stack);

void push_seq(p_seq_stack stack, data_type x);

void pop_seq(p_seq_stack stack);

data_type top_seq(p_seq_stack stack);

/* queue */
struct seq_queue {
    int maxn;
    int head, tail;
    data_type *q;
};
typedef struct seq_queue *p_seq_queue;

p_seq_queue create_empty_queue_seq(int n);

int is_empty_queue_seq(p_seq_queue queue);

void enQueue_seq(p_seq_queue queue, data_type x);

void deQueue_seq(p_seq_queue queue);

data_type frontQueue_seq(p_seq_queue queue);

#endif //ALGOCLASS_GRAPH_H
