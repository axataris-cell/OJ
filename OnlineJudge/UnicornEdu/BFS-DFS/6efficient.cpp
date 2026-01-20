#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 5;
vector<int> g[MAXN];
int sub[MAXN];

void dfs(int u) {
    sub[u] = 1;
    for (int v : g[u]) {
        dfs(v);
        sub[u] += sub[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << sub[i] - 1 << " ";
    }
}
