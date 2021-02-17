//
// Created by LanFear on 2021/2/17.
//

#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
const int N = 1e4;

// 1. plain dijkstra algorithm with adjacent matrix
int graph[N][N];
int dist[N];
bool vis[N];
int vertices, edges;

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[1] = 0;
    for (size_t i = 1; i < vertices; ++i) {

        // find the minimum dist vertex
        int x = 0;
        for (size_t j = 1; j <= vertices; ++j) {
            if (!vis[j] && (x == 0 || dist[j] < dist[x])) {
                x = j;
            }
        }
        vis[x] = true;

        // update dist info
        for (size_t y = 1; y <= vertices; ++y) {
            dist[y] = min(dist[y], dist[x] + graph[x][y]);
        }
    }
}

int main() {
    int src, dest, weight;
    cin >> vertices >> edges;

    // initialization
    memset(graph, 0x3f, sizeof graph);
    for (size_t i = 1; i <= vertices; ++i) {
        graph[i][i] = 0;
    }
    for (size_t i = 1; i <= edges; ++i) {
        cin >> src >> dest >> weight;
        graph[src][dest] = min(graph[src][dest], weight);
    }
    dijkstra();
    for (size_t i = 1; i <= vertices; ++i) {
        cout << dist[i] << endl;
    }
    return 0;
}

/* test case
4 6
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
*/