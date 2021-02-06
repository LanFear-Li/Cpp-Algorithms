//
// Created by lanfear on 2021/2/6.
//

#include "iostream"
#include "vector"
#include "queue"
#include "stack"
using namespace std;

const int MAXN = 1e5;
int vertices, edges, front, after;
vector<int> edge[MAXN];
stack<int> Stack;
vector<bool> inStack(vertices, false);
vector<int> sequence(vertices, 0);
vector<int> place(vertices, 0);
vector<vector<int>> scc(vertices, vector<int> ());
int sccScale = 0, index = 0;

// maybe memorized DFS?
// searching for stronglyConnectedComponents with Tarjan
void tarjan(const int& x) {
    index += 1;
    sequence[x] = index;
    place[x] = index;
    Stack.push(x);
    inStack[x] = true;
    for (int vertex : edge[x]) {
        if (sequence[vertex] == 0) {
            tarjan(vertex);
            place[x] = min(place[x], place[vertex]);
        } else if (inStack[vertex]) {
            place[x] = min(place[x], place[vertex]);
        }
    }
    if (sequence[x] == place[x]) {
        sccScale += 1;
        int node;
        do {
            node = Stack.top();
            Stack.pop();
            inStack[node] = false;
            scc[sccScale - 1].push_back(node);
        } while (node != x);
    }
}


