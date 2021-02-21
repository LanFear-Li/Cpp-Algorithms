//
// Created by lanfear on 2021/2/17.
//

#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
const int N = 1e5 + 100;
const int INF = 0x3f3f3f3f;

int graph[N][N];            // 邻接矩阵存图
int parent[N];              // 存储MST
int dis[N];                 // 存储外部点到MST集合的距离
bool isInSet[N];            // 判断点是否属于MST集合
int vertices, edges;        // 图顶点与边
int minimumCost;            // MST最小代价

int minDistance() {
    int Min = INF, res;
    for (size_t i = 0; i < vertices; ++i) {
        if (!isInSet[i] && dis[i] < Min) {
            Min = dis[i];
            res = i;
        }
    }
    return res;
}

void prim() {
    memset(dis, INF, sizeof dis);
    for (size_t i = 0; i < vertices; ++i) {
        dis[i] = INF;
        isInSet[i] = false;
    }

    // 默认首个节点作为MST树根
    dis[0] = 0;
    parent[0] = -1;

    for (size_t i = 0; i < vertices - 1; ++i) {
        int pickedVertex = minDistance();
        minimumCost += dis[pickedVertex];
        isInSet[pickedVertex] = true;
        for (size_t j = 0; j < vertices; ++j) {
            if (graph[pickedVertex][j] && !isInSet[j] && graph[pickedVertex][j] < dis[j]) {
                parent[j] = pickedVertex;
                dis[j] = graph[pickedVertex][j];
            }
        }
    }
}

int main() {
    int src, dest, weight;
    cin >> vertices >> edges;
    memset(graph, INF, sizeof graph);
    for (int i = 1; i <= edges; ++i) {
        cin >> src >> dest >> weight;
        graph[src][dest] = min(graph[src][dest], weight);
        graph[dest][src] = graph[src][dest];
    }
    prim();
    cout << minimumCost << endl;
    return 0;
}