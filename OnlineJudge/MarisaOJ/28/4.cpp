#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

int n, m;
vector<pair<int,int>> g[MAXN];
vector<ll> dist;
vector<int> dp;
vector<int> adj[MAXN];

void dijkstra(int s) {
    dist.assign(n + 1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra(1);

    // build DAG of shortest paths
    for (int u = 1; u <= n; u++) {
        for (auto [v, w] : g[u]) {
            if (dist[u] + w == dist[v]) {
                adj[u].push_back(v);
            }
        }
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 1);
    sort(order.begin(), order.end(),
         [&](int a, int b) { return dist[a] < dist[b]; });

    dp.assign(n + 1, 0);
    dp[1] = 1;

    for (int u : order) {
        for (int v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }

    cout << dp[n];
    return 0;
}