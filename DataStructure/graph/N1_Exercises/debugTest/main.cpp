#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 100;

struct Edge {
    int src, dest;
    int weight;
} edge[MAXN];

int parent[5010];
int vertices, edges;
long long int minimumCost, cnt;

bool cmp(const Edge& x, const Edge& y) {
    return x.weight < y.weight;
}

int findRoot(const int& x) {
    return parent[x] == x ? x : findRoot(parent[x]);
}

bool kruskal() {
    for (int i = 1; i <= vertices; ++i) {
        parent[i] = i;
    }
    sort(edge + 1, edge + 1 + edges, cmp);
    for (int i = 1; i <= edges; ++i) {
        int x = findRoot(edge[i].src);
        int y = findRoot(edge[i].dest);
        if (x == y) continue;
        parent[y] = x;
        minimumCost += edge[i].weight;
        cnt += 1;
        if (cnt == vertices - 1) return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &vertices, &edges);
    for (int i = 1; i <= edges; ++i) {
        scanf("%d %d %d", &edge[i].src, &edge[i].dest, &edge[i].weight);
    }
    if (kruskal()) {
        printf("%lld", minimumCost);
    } else {
        printf("orz");
    }
    return 0;
}