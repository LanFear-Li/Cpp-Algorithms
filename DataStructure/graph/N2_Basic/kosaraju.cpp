//
// Created by lanfear on 2021/2/10.
//

#include "iostream"
#include "vector"
#include "queue"
#include "stack"
using namespace std;

const int MAXN = 1e5;
int vertices, edges, front, after;
vector<int> edge[MAXN], tEdge[MAXN];
vector<int> SCC(MAXN, 0);
stack<int> Stack;
bool vis[MAXN];
int color; // type of scc

void firstDFS(const int& x) {
    if (vis[x]) {
        return;
    }
    vis[x] = true;
    for (int i : edge[x]) {
        firstDFS(i);
    }
    Stack.push(x);
}

void secondDFS(const int& x) {
    if (SCC[x]) {
        return;
    }
    SCC[x] = color;
    for (int i : tEdge[x]) {
        secondDFS(i);
    }
}

void kosaraju() {
    while (!Stack.empty()) {
        Stack.pop();
    }
    for (int i = 1; i <= vertices; ++i) {
        firstDFS(i);
    }
    while (!Stack.empty()) {
        if (!SCC[Stack.top()]) {
            color += 1;
            secondDFS(Stack.top());
        }
        Stack.pop();
    }
}

int main() {
    cin >> vertices >> edges;
    for (int i = 0; i < edges; ++i) {
        cin >> front >> after;
        edge[front].push_back(after);
        tEdge[after].push_back(front);
    }
    kosaraju();
    for (int i = 1; i <= vertices; ++i) {
        cout << "the" << i << "th vertex belongs to " << SCC[i] << "th SCC" << endl;
    }
    return 0;
}