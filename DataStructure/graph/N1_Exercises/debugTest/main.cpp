//
// Created by LanFear on 2021/2/17.
//

#include "iostream"
#include "algorithm"
#include "cstring"
#include "queue"
using namespace std;
const int N = 1e4;
typedef pair<int, int> PII;

int head[N], ver[N],edge[N], Next[N];
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
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (!heap.empty()) {
        int x = heap.top().second;
        heap.pop();
        if (vis[x]) {
            continue;
        } else {
            vis[x] = true;
            for (int i = head[x]; i; i = Next[i]) {
                int y = ver[i], z = edge[i];
                if (dist[y] > dist[x] + z) {
                    dist[y] = dist[x] + z;
                    heap.push({dist[y], y});
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

/* test case
4 6
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
*/