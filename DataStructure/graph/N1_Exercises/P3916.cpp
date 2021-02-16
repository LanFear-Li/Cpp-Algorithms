// Created by LanFear on 2021/2/4
// 反向建图DFS
// Luogu

#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1e5 + 10;

vector <int> graph[Maxn];
int arr[Maxn];

void DFS(const int &x, const int &y) {
    if (arr[x]) {
        return;
    }
    arr[x] = y;
    for (auto i : graph[x]) {
        DFS(i, y);
    }
}

int main() {
	int n, m, x, y;
    cin >> n >> m;
    for (size_t i = 1; i <= m; ++i) {
        cin >> x >> y;
        graph[y].push_back(x);
    }
    for (size_t i = n; i >= 1; --i) {
        DFS(i, i);
    }
    for (int i = 1; i <= n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
