#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000005;

vector<int> adj[MAXN];
int sz[MAXN], depth[MAXN], heavy[MAXN];
int tin[MAXN], tout[MAXN], ver[MAXN];
int cnt[MAXN];
int timer = 0;
int n, k;
long long ans = 0;

void dfs1(int u, int p, int d) {
    tin[u] = ++timer;
    ver[timer] = u;
    depth[u] = d;
    sz[u] = 1;

    for (int v : adj[u]) {
        if (v != p) {
            dfs1(v, u, d + 1);
            sz[u] += sz[v];
            if (sz[v] > sz[heavy[u]]) {
                heavy[u] = v;
            }
        }
    }

    tout[u] = timer;
}

void dfs_dsu(int u, int p, bool keep) {
    for (int v : adj[u]) {
        if (v != p && v != heavy[u]) {
            dfs_dsu(v, u, false);
        }
    }

    if (heavy[u] != 0) {
        dfs_dsu(heavy[u], u, true);
    }

    for (int v : adj[u]) {
        if (v != p && v != heavy[u]) {
            for (int i = tin[v]; i <= tout[v]; i++) {
                int x = ver[i];
                int target_d = k + 2 * depth[u] - depth[x];
                if (target_d >= 1 && target_d <= n) {
                    ans += cnt[target_d];
                }
            }

            for (int i = tin[v]; i <= tout[v]; i++) {
                int x = ver[i];
                cnt[depth[x]]++;
            }
        }
    }

    int target_d = k + depth[u];
    if (target_d >= 1 && target_d <= n) {
        ans += cnt[target_d];
    }

    cnt[depth[u]]++;

    if (!keep) {
        for (int i = tin[u]; i <= tout[u]; i++) {
            cnt[depth[ver[i]]]--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> k)) return 0;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0, 1);
    dfs_dsu(1, 0, true);

    cout << ans << '\n';

    return 0;
}