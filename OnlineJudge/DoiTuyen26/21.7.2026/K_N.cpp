#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define null nullptr
#define pb push_back
#define len length
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-07-21 21:07

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "K_N"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int LOG = 20;

struct Edge {
    int to, weight;
};

int n, T;
vector<vector<Edge>> adj;
vector<int> tin, tout, depth;
vector<vector<int>> up, mn;
int timer = 0;

void dfs(int u, int p, int w_p) {
    tin[u] = ++timer;
    up[u][0] = p;
    mn[u][0] = w_p;

    for (int j = 1; j < LOG; ++j) {
        up[u][j] = up[up[u][j - 1]][j - 1];
        mn[u][j] = min(mn[u][j - 1], mn[up[u][j - 1]][j - 1]);
    }

    for (auto& edge : adj[u]) {
        int v = edge.to;
        int w = edge.weight;
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u, w);
        }
    }

    tout[u] = ++timer;
}

bool anc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (anc(u, v)) return u;
    if (anc(v, u)) return v;

    for (int j = LOG - 1; j >= 0; --j) {
        if (!anc(up[u][j], v)) {
            u = up[u][j];
        }
    }

    return up[u][0];
}

int getmn(int v, int u) {
    int res = INF;

    for (int j = LOG - 1; j >= 0; --j) {
        if (depth[v] - (1 << j) >= depth[u]) {
            res = min(res, mn[v][j]);
            v = up[v][j];
        }
    }

    return res;
}

struct DSU {
    vector<int> parent;
    vector<bool> has_key;

    void init(const vector<int>& nodes, const vector<int>& keys) {
        for (int u : nodes) {
            parent[u] = u;
            has_key[u] = false;
        }

        for (int k : keys) {
            has_key[k] = true;
        }
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        int ru = find(u);
        int rv = find(v);

        if (ru != rv) {
            if (has_key[ru] && has_key[rv]) {
                return true;
            }

            parent[ru] = rv;
            has_key[rv] = has_key[rv] | has_key[ru];
        }

        return false;
    }
} dsu;

void solve_query() {
    int k; cin >> k;

    vector<int> S(k);
    for (int i = 0; i < k; ++i) cin >> S[i];

    if (k <= 1) {
        cout << 0 << el;
        return;
    }

    sort(S.begin(), S.end(), [](int a, int b) {
        return tin[a] < tin[b];
    });

    vector<int> virtual_nodes = S;

    for (int i = 0; i < k - 1; ++i) {
        virtual_nodes.push_back(lca(S[i], S[i + 1]));
    }

    sort(virtual_nodes.begin(), virtual_nodes.end(), [](int a, int b) {
        return tin[a] < tin[b];
    });

    virtual_nodes.erase(unique(virtual_nodes.begin(), virtual_nodes.end()), virtual_nodes.end());

    vector<tuple<int, int, int>> virtual_edges;
    stack<int> st;
    st.push(virtual_nodes[0]);

    for (size_t i = 1; i < virtual_nodes.size(); ++i) {
        int u = virtual_nodes[i];

        while (!anc(st.top(), u)) {
            st.pop();
        }

        int p = st.top();
        int w = getmn(u, p);

        virtual_edges.push_back({w, p, u});
        st.push(u);
    }

    sort(virtual_edges.rbegin(), virtual_edges.rend());

    dsu.init(virtual_nodes, S);

    int ans = 0;

    for (auto& edge : virtual_edges) {
        int w = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);

        if (dsu.unite(u, v)) {
            ans = w;
            break;
        }
    }

    cout << ans << el;
}

void testcase() {
    cin >> n;

    adj.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    depth.resize(n + 1);
    up.assign(n + 1, vector<int>(LOG, 0));
    mn.assign(n + 1, vector<int>(LOG, INF));
    dsu.parent.resize(n + 1);
    dsu.has_key.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, 1, INF);

    cin >> T;

    while (T--) {
        solve_query();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}