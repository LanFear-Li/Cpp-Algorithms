//
// Created by LanFear on 2021/2/17.
//

#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
const int N = 1e5 + 100;
const int INF = 0xfffffff;

// 1. plain dijkstra algorithm with adjacent matrix
int graph[N][N];
int dist[N];
bool vis[N];
int vertices, edges;

void dijkstra() {
    memset(dist, INF, sizeof dist);
    dist[1] = 0;
    for (size_t i = 1; i < vertices; ++i) {

        // find the minimum dist vertex
        int x = 1;
        for (size_t j = 1; j <= vertices; ++j) {
            if (!vis[j] && dist[j] < dist[x]) {
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
    memset(graph, INF, sizeof graph);
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

// 2. q optimized dijkstra algorithm with priority queue
typedef pair<int, int> PII;

int head[N], ver[N], edge[N], Next[N];
int dist[N];
bool vis[N];
int vertices, edges, tot;

void add(int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});

    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) {
            continue;
        } else {
            vis[x] = true;
            for (int i = head[x]; i; i = Next[i]) {
                int y = ver[i], z = edge[i];
                if (dist[y] > dist[x] + z) {
                    dist[y] = dist[x] + z;
                    q.push({dist[y], y});
                }
            }
        }
    }
}

int main() {
    int src, dest, weight;
    cin >> vertices >> edges;

    // initialization
    for (size_t i = 1; i <= edges; ++i) {
        cin >> src >> dest >> weight;
        add(src, dest, weight);
    }
    dijkstra();
    for (size_t i = 1; i <= vertices; ++i) {
        cout << dist[i] << endl;
    }
    return 0;
}