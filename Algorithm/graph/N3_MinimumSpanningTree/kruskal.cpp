//
// Created by lanfear on 2021/2/16.
//

#include "iostream"
#include "algorithm"
using namespace std;
const int MAXN = 1e5 + 100;

struct Edge {
    int src, dest;
    int weight;
} edge[MAXN];

int parent[MAXN];
int vertices, edges;
int minimumCost, cnt;

bool cmp(const Edge& x, const Edge& y) {
    return x.weight < y.weight;
}

int findRoot(const int& x) {
    return parent[x] == x ? x : findRoot(parent[x]);
}

void kruskal() {
    for (size_t i = 1; i <= vertices; ++i) {
        parent[i] = i;
    }
    sort(edge + 1, edge + 1 + edges, cmp);
    for (size_t i = 1; i <= edges; ++i) {
        int x = findRoot(edge[i].src);
        int y = findRoot(edge[i].dest);
        if (x == y) {
            continue;
        } else if (cnt == vertices - 1) {
            break;
        } else {
            parent[y] = x;
            minimumCost += edge[i].weight;
            cnt += 1;
        }
    }
}

int main() {
    cin >> vertices >> edges;
    for (int i = 1; i <= edges; ++i) {
        cin >> edge[i].src >> edge[i].dest >> edge[i].weight;
    }
    kruskal();
    cout << minimumCost << endl;
    return 0;
}