#include "iostream"
#include "vector"
#include "queue"
#include <cstring>
#include "algorithm"
using namespace std;

const int MAXN = 1e5;

vector<int> edge[MAXN];
vector<int> DFSGraph, BFSGraph;
int vis[MAXN];

void DFS(const int &x) {
    vis[x] = 1;
    for (auto cur : edge[x]) {
        if (!vis[cur]) {
            DFSGraph.push_back(cur);
            DFS(cur);
        }
    }
}

void BFS(const int &x) {
    queue <int> q;
    q.push(x);
    vis[x] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        BFSGraph.push_back(cur);
        for (auto i : edge[cur]) {
            if (!vis[i]) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

vector<int> topolpgicalSort(const int& vertices, const vector<vector<int>>& edges) {
    vector<vector<int>> graph(vertices, vector<int>());
    vector<int> indegree(vertices, 0), res;
    for (const auto & cur : edges) {
        graph[cur[1]].push_back(cur[0]);
        indegree[cur[0]] += 1;
    }
    queue<int> q;
    for (int i = 0; i < indegree.size(); ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (q.empty() == 0) {
        int cur = q.front();
        res.push_back(cur);
        q.pop();
        for (auto vertex : graph[cur]) {
            indegree[vertex] -= 1;
            if (indegree[vertex] == 0) {
                q.push(vertex);
            }
        }
    }
    for (auto i : indegree) {
        if (i) {
            return vector<int>();
        }
    }
    return res;
}

int main(){
    int vertices, edges, front, after;
    cin >> vertices >> edges;
    for (size_t i = 1; i <= edges; ++i) {
        cin >> front >> after;
        edge[front].push_back(after);
    }
    return 0;
}