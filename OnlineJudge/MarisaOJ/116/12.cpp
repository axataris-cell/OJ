#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;
const int INF = 1e9;

int n, m, k;
int p[MAXN];
int dp[MAXN][MAXN];
vector<int> adj[MAXN];

void bfs(int src, int id) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        dp[id][i] = dist[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) cin >> p[i];

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < k; i++)
        bfs(p[i], i);

    int res = INF;

    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) if (u < v) {
            int sum = 0;
            bool ok = true;

            for (int i = 0; i < k; i++) {
                int du = dp[i][u];
                int dv = dp[i][v];

                if (du == -1 && dv == -1) {
                    ok = false;
                    break;
                }
                if (du == -1) sum += dv;
                else if (dv == -1) sum += du;
                else sum += min(du, dv);

                if (sum >= res) break;
            }

            if (ok) res = min(res, sum);
        }
    }

    cout << res << '\n';
    return 0;
}
