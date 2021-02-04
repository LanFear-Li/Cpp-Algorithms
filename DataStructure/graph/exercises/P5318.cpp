// Created by LanFear on 2021/2/3
// DFS, BFS图遍历
// Luogu

#include "iostream"
#include "vector"
#include "queue"
#include <cstring>
#include "algorithm"
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;

const int MAXN = 1e5;

vector <int> edge[MAXN];
vector <int> DFSGraph, BFSGraph;
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

int main(){
    int nodes, operators, front, after;
    cin >> nodes >> operators;
    for (size_t i = 1; i <= operators; ++i) {
        cin >> front >> after;
        edge[front].push_back(after);
    }
    for(size_t i = 1;i <= nodes; ++i) {
        sort(edge[i].begin(), edge[i].end());//将所有节点的毗邻节点从大到小排序
    }
    ms(vis,0);
    DFSGraph.push_back(1);
    DFS(1);
    for (auto i : DFSGraph) {
        cout << i << " ";
    }
    cout << endl;
    ms(vis,0);
    BFS(1);
    for (auto i : BFSGraph) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}