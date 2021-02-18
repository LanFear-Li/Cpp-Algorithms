//
// Created by lanfear on 2021/2/18.
//

const int N = 1e5;

// 1. adjacent matrix *******************************************************************
int graph[N][N];

// 2. adjacency list (array) ************************************************************
int head[N], ver[N], edge[N], Next[N];
int index;

void add(int x, int y, int z) {
    ver[++index] = y;
    edge[index] = z;
    Next[index] = head[x];
    head[x] = index;
}

// 3. adjacency list (vector) ***********************************************************
struct Edge {
    int src, dest;
    int weight;
    Edge(int _src, int _dest, int _weight): src(_src), dest(_dest), weight(_weight) {}
};

vector<Edge> G[N];

// 4. linked front-end star *****************************************************************
struct Edge {
    int next, to;
    int weight;
} edge[N];

int head[N];

void addEdge(int u, int v, int w) {
    edge[index].weight = w;
    edge[index].to = v;
    edge[index].next = head[u];
    head[u] = index++;
}