#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

// Trọng số tối đa (0 <= w <= 9)
const int MAX_W = 9; 

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

    // Thuật toán Dial: Chỉ cần dùng mảng kích thước MAX_W + 1
    vector<vector<int>> bucket(MAX_W + 1);
    bucket[0].push_back(s);

    int count = 1; // Đếm số lượng phần tử đang nằm trong tất cả các bucket
    ll d = 0;      // Lưu khoảng cách hiện tại đang xét

    while (count > 0) {
        // Nếu bucket tại khoảng cách d đang rỗng, tiến tới khoảng cách d+1
        while (bucket[d % (MAX_W + 1)].empty()) {
            d++;
        }

        // Lấy đỉnh ra khỏi bucket
        int u = bucket[d % (MAX_W + 1)].back();
        bucket[d % (MAX_W + 1)].pop_back();
        count--;

        // Lazy deletion: bỏ qua nếu đã tìm được đường ngắn hơn tới u từ trước
        if (dist[u] != d) continue;

        // Tối ưu: Dừng sớm nếu đã tìm ra khoảng cách ngắn nhất đến đích
        if (u == t) break;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                
                // Đẩy vào bucket tương ứng theo vòng tròn (modulo MAX_W + 1)
                bucket[dist[v] % (MAX_W + 1)].push_back(v);
                count++;
            }
        }
    }

    if (dist[t] == INF) cout << -1;
    else cout << dist[t];

    return 0;
}