#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

struct Edge {
    int to, w;
};

void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;

    vector<vector<Edge>> g(n + 1), g_rev(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g_rev[v].push_back({u, w});
    }

    vector<vector<int>> dist_A(n + 1, vector<int>(a + 1, INF));
    using StateA = tuple<int, int, int>;
    priority_queue<StateA, vector<StateA>, greater<StateA>> pqA;

    dist_A[1][0] = 0;
    pqA.emplace(0, 1, 0);

    while (!pqA.empty()) {
        auto [d, u, k] = pqA.top(); pqA.pop();
        if (d > dist_A[u][k]) continue;

        for (auto &e : g[u]) {
            int v = e.to, w = e.w;

            if (dist_A[v][k] > d + w) {
                dist_A[v][k] = d + w;
                pqA.emplace(dist_A[v][k], v, k);
            }
            if (k < a && dist_A[v][k + 1] > d) {
                dist_A[v][k + 1] = d;
                pqA.emplace(dist_A[v][k + 1], v, k + 1);
            }
        }
    }

    vector<int> f(n + 1, INF);
    for (int u = 1; u <= n; u++) {
        for (int k = 0; k <= a; k++) {
            f[u] = min(f[u], dist_A[u][k]);
        }
    }
    vector<vector<array<int, 2>>> dist_M(n + 1, vector<array<int, 2>>(b + 1, {INF, INF}));
    using StateM = tuple<int, int, int, int>;
    priority_queue<StateM, vector<StateM>, greater<StateM>> pqM;

    for (int u = 1; u <= n; u++) {
        if (f[u] != INF) {
            dist_M[u][0][0] = f[u];
            pqM.emplace(f[u], u, 0, 0);
        }
    }

    while (!pqM.empty()) {
        auto [d, u, k, s] = pqM.top(); pqM.pop();
        if (d > dist_M[u][k][s]) continue;

        for (auto &e : g_rev[u]) {
            int v = e.to, w = e.w;

            if (dist_M[v][k][1] > d + w) {
                dist_M[v][k][1] = d + w;
                pqM.emplace(dist_M[v][k][1], v, k, 1);
            }
            if (k < b && dist_M[v][k + 1][s] > d + 2 * w) {
                dist_M[v][k + 1][s] = d + 2 * w;
                pqM.emplace(dist_M[v][k + 1][s], v, k + 1, s);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        int ans = INF;
        ans = min({ans, dist_M[i][b][0], dist_M[i][b][1]});
        
        for (int k = 0; k < b; k++) {
            ans = min(ans, dist_M[i][k][0]);
        }

        cout << (ans >= INF / 2 ? -1 : ans) << (i == n ? "" : " ");
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}