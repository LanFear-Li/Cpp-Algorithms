//
// Created by lanfear on 2021/2/19.
//

#include "iostream"
#include "algorithm"
#include "cstring"
#include "queue"
using namespace std;
const int N = 1e5 + 100;
const int INF = 0xfffffff;

typedef pair<int, int> PII;

int head[N], ver[N], edge[N], Next[N];
queue<int> q;
int dist[N];
bool vis[N];
int vertices, edges, tot;

void add(int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}

void SPFA() {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[1] = 0;

    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (dist[y] > dist[x] + z) {
                dist[y] = dist[x] + z;
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = true;
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

    SPFA();

    for (size_t i = 1; i <= vertices; ++i) {
        cout << dist[i] << endl;
    }
    return 0;
}