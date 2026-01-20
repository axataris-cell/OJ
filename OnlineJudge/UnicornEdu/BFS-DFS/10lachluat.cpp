#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll NEG_INF = -4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    cin.ignore(); // bỏ '\n'

    vector<vector<pair<int,ll>>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    bool hasWeight = false;

    // đọc từng dòng cạnh
    for (int i = 0; i < m; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        int u, v;
        ll w = 1; // mặc định không trọng số

        ss >> u >> v;
        if (ss >> w) {
            hasWeight = true; // phát hiện trọng số
        }

        adj[u].push_back({v, w});
        indeg[v]++;
    }

    int s, t;
    cin >> s >> t;

    // topo sort Kahn
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto &e : adj[u]) {
            int v = e.first;
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    // có chu trình
    if ((int)topo.size() < n) {
        cout << 0;
        return 0;
    }

    // DP longest path
    vector<ll> dp(n + 1, NEG_INF);
    dp[s] = 0;

    for (int u : topo) {
        if (dp[u] == NEG_INF) continue;
        for (auto &e : adj[u]) {
            int v = e.first;
            ll w = e.second;
            dp[v] = max(dp[v], dp[u] + w);
        }
    }

    if (dp[t] == NEG_INF) cout << 0;
    else cout << dp[t];

    return 0;
}
