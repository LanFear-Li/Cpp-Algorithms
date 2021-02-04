#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

vector<int> topolpgicalSort(const int& vertices, const vector<vector<int> >& edges) {
    vector<vector<int> > graph(vertices, vector<int>());
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
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> input(m, vector<int>());
    for (size_t i = 0; i < m; ++i) {
        cin >> x >> y;
        input[i].push_back(x);
        input[i].push_back(y);
    }
    vector<int> res = topolpgicalSort(n, input);
    for (auto i : res) {
        cout << i << " ";
    }
    return 0;
}
