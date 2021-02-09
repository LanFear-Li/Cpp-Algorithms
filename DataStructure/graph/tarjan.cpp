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
vector<bool> inStack(MAXN, false);
vector<int> sequence(MAXN, 0);
vector<int> place(MAXN, 0);
vector<vector<int>> scc(MAXN, vector<int> ());
int sccScale, idx = 0;

// maybe memorized DFS?
// searching for stronglyConnectedComponents with Tarjan
void tarjan(const int& x) {
    idx += 1;
    sequence[x] = idx;
    place[x] = idx;
    Stack.push(x);
    inStack[x] = true;
    for (int vertex : edge[x]) {
        if (sequence[vertex] == 0) {
            tarjan(vertex);
            place[x] = min(place[x], place[vertex]);
        } else if (inStack[vertex]) {
            place[x] = min(place[x], sequence[vertex]);
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

int main() {
    cin >> vertices >> edges;
    for (size_t i = 1; i <= edges; ++i) {
        cin >> front >> after;
        edge[front].push_back(after);
    }
    tarjan(1);
    cout << "sccScale is: " << sccScale << endl;
    for (size_t i = 0; i < sccScale; ++i) {
        for (int j : scc[i]) {
            cout << j << '\t';
        }
        cout << endl;
    }
    return 0;
}


