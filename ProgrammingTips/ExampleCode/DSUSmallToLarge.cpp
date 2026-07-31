#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

int n, m;
int col[MAXN];
vector<int> adj[MAXN];

struct Query {
    int k;
    int id;
};

vector<Query> queries[MAXN];
int ans[MAXN];

int sz[MAXN], heavy[MAXN], in[MAXN], out[MAXN], node_at[MAXN];
int timer = 0;

int color_freq[MAXN];
int freq_count[MAXN];

void dfs1(int v, int p) {
    sz[v] = 1;
    heavy[v] = 0;
    in[v] = ++timer;
    node_at[timer] = v;

    int max_sub_size = 0;
    for (int u : adj[v]) {
        if (u != p) {
            dfs1(u, v);
            sz[v] += sz[u];
            if (sz[u] > max_sub_size) {
                max_sub_size = sz[u];
                heavy[v] = u;
            }
        }
    }

    out[v] = timer;
}

void add(int v) {
    int c = col[v];
    color_freq[c]++;
    freq_count[color_freq[c]]++;
}

void remove(int v) {
    int c = col[v];
    freq_count[color_freq[c]]--;
    color_freq[c]--;
}

void dfs2(int v, int p, bool keep) {
    for (int u : adj[v]) {
        if (u != p && u != heavy[v]) {
            dfs2(u, v, false);
        }
    }

    if (heavy[v]) {
        dfs2(heavy[v], v, true);
    }

    add(v);

    for (int u : adj[v]) {
        if (u != p && u != heavy[v]) {
            for (int i = in[u]; i <= out[u]; ++i) {
                add(node_at[i]);
            }
        }
    }

    for (auto q : queries[v]) {
        ans[q.id] = freq_count[q.k];
    }

    if (!keep) {
        for (int i = in[v]; i <= out[v]; ++i) {
            remove(node_at[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> col[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= m; ++i) {
        int v, k;
        cin >> v >> k;
        queries[v].push_back({k, i});
    }

    dfs1(1, 0);
    dfs2(1, 0, true);

    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}