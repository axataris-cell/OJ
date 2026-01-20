#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    vector<int> dist(n+1, 0);
    priority_queue<pair<int,int>> pq;

    dist[s] = INT_MAX;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        auto [cap, u] = pq.top();
        pq.pop();

        if (cap < dist[u]) continue;
        if (u == t) break;

        for (auto &[v, w] : adj[u]) {
            int new_cap = min(cap, w);
            if (new_cap > dist[v]) {
                dist[v] = new_cap;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[t] << '\n';
    return 0;
}
