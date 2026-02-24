#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

// 0 <= w <= 9

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    int s, t;
    cin >> s >> t;

    vector<ll> dist(n + 1, INF);
    dist[s] = 0;

    int maxDist = 9 * n;
    vector<vector<int>> bucket(maxDist + 1);

    bucket[0].push_back(s);

    for (int d = 0; d <= maxDist; d++) {
        while (!bucket[d].empty()) {
            int u = bucket[d].back();
            bucket[d].pop_back();

            if (dist[u] != d) continue;

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    bucket[dist[v]].push_back(v);
                }
            }
        }
    }

    if (dist[t] == INF) cout << -1;
    else cout << dist[t];

    return 0;
}