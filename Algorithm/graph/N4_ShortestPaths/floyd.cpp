//
// Created by lanfear on 2021/2/19.
//

#include "iostream"
#include "cstring"
using namespace std;
const int N = 1e4 + 100;

int graph[N][N];
int vertices, edges;

int main() {
    cin >> vertices >> edges;
    memset(graph, 0x3f, sizeof graph);

    for (size_t i = 1; i < vertices; ++i) {
        graph[i][i] = 0;
    }
    for (size_t i = 1; i <= edges; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src][dest] = min(graph[src][dest], weight);
    }

    // floyd(dp)
    for (size_t k = 1; k <= vertices; ++k) {
        for (size_t i = 1; i <= vertices; ++i) {
            for (size_t j = 1; j <= vertices; ++j) {
                graph[i][j] =   min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (size_t i = 1; i <= vertices; ++i) {
        for (size_t j = 1; j <= vertices; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}