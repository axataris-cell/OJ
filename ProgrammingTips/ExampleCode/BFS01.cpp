#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m; // số đỉnh, số cạnh

    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // w chỉ là 0 hoặc 1
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // bỏ dòng này nếu đồ thị có hướng
    }

    int s;
    cin >> s; // đỉnh bắt đầu

    vector<int> dist(n + 1, INF);
    deque<int> dq;

    dist[s] = 0;
    dq.push_front(s);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }

    // In kết quả
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
}
