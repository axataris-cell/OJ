#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 10;

struct edge {
    int u, v;
    bool used;
    int other(int x) {
        return u ^ v ^ x;
    }
};

int n, m, timeDfs = 0, bridge = 0;
int low[maxN], num[maxN];
vector<int> g[maxN];
edge E[maxN * 2];

void minimize(int &a, int b) {
    if (a > b) a = b;
}

void dfs(int u) {
    num[u] = low[u] = ++timeDfs;
    for (int i : g[u]) {
        edge &e = E[i];
        if (e.used) continue;
        e.used = true;
        int v = e.other(u);
        if (!num[v]) {
            dfs(v);
            minimize(low[u], low[v]);
            if (low[v] > num[u]) bridge++;
        } else {
            minimize(low[u], num[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(i);
        g[v].push_back(i);
        E[i] = {u, v};
    }

    cin >> m;
    m += n - 1;
    for (int i = n; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(i);
        g[v].push_back(i);
        E[i] = {u, v};
    }

    dfs(1);
    cout << bridge;
}