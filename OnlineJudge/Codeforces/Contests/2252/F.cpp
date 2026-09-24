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
// Created: 2026-08-06 22:34

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "F"

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

#define int long long

struct Edge {
    int to;
    int dist;
};

const int MAXN = 2e5 + 5;
const int LOGN = 20;

vector<int> g[MAXN];
int par[MAXN][LOGN];
int h[MAXN];
int tin[MAXN], tout[MAXN];
int timeDfs;

void dfs(int u, int p, int d) {
    tin[u] = ++timeDfs;
    h[u] = d;
    par[u][0] = p;
    for (int i = 1; i < LOGN; ++i) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
    tout[u] = timeDfs;
}

bool isanc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (isanc(u, v)) return u;
    if (isanc(v, u)) return v;
    for (int i = LOGN - 1; i >= 0; --i) {
        if (!isanc(par[u][i], v)) {
            u = par[u][i];
        }
    }
    return par[u][0];
}

void testcase() {
    int n; cin >> n;

    vector<int> c(n + 1);
    vector<vector<int>> color(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        color[c[i]].pb(i);
    }

    vector<int> k(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }

    for (int i = 1; i <= n; ++i) {
        g[i].clear();
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    timeDfs = 0;
    dfs(1, 1, 0);

    vector<vector<Edge>> VT(n + 1);
    vector<int> bruh(n + 1, 0);
    vector<int> colcnt(n + 1, 0);
    vector<int> ans(n + 1, -1);

    for (int col = 1; col <= n; ++col) {
        if (color[col].empty()) {
            ans[col] = -1;
            continue;
        }

        const auto &curcol = color[col];
        int cursz = curcol.size();
        int curk = k[col];

        if (cursz == 1) {
            ans[col] = 0;
            continue;
        }

        vector<int> nodes = curcol;
        sort(all(nodes), [](int a, int b) {
            return tin[a] < tin[b];
        });

        int sz = nodes.size();
        for (int i = 0; i < sz - 1; ++i) {
            nodes.pb(lca(nodes[i], nodes[i + 1]));
        }

        sort(all(nodes), [](int a, int b) {
            return tin[a] < tin[b];
        });

        nodes.erase(unique(all(nodes)), nodes.end());

        for (int u : curcol) {
            bruh[u] = 1;
        }

        vector<int> st;
        st.pb(nodes[0]);

        for (size_t i = 1; i < nodes.size(); ++i) {
            int u = nodes[i];
            while (!st.empty() && !isanc(st.back(), u)) {
                st.pop_back();
            }
            int p = st.back();
            int d = h[u] - h[p];
            VT[p].pb({u, d});
            VT[u].pb({p, d});
            st.pb(u);
        }

        auto dfs2 = [&](auto &self, int u, int p) -> void {
            colcnt[u] = bruh[u];
            for (auto &edge : VT[u]) {
                int v = edge.to;
                if (v != p) {
                    self(self, v, u);
                    colcnt[u] += colcnt[v];
                }
            }
        };

        dfs2(dfs2, nodes[0], -1);

        int root = nodes[0];
        int prevroot = -1;

        while (true) {
            int nxt = -1;
            for (auto &edge : VT[root]) {
                int v = edge.to;
                if (v != prevroot && colcnt[v] > cursz / 2) {
                    nxt = v;
                    break;
                }
            }
            if (nxt == -1) break;
            prevroot = root;
            root = nxt;
        }

        int total = 0;
        vector<pll> edges;

        auto dfs3 = [&](auto &self, int u, int p) -> int {
            int cnt = bruh[u];
            for (auto &edge : VT[u]) {
                int v = edge.to;
                int d = edge.dist;
                if (v == p) continue;
                int w = self(self, v, u);
                total += w * d;
                edges.pb({w, d});
                cnt += w;
            }
            return cnt;
        };

        dfs3(dfs3, root, -1);

        sort(rall(edges));

        int rem = curk - 1;
        int reduce = 0;

        for (auto &[w, d] : edges) {
            if (rem == 0) break;
            int take = min(rem, d);
            reduce += take * w;
            rem -= take;
        }

        ans[col] = total - reduce;

        for (int u : nodes) {
            VT[u].clear();
            bruh[u] = 0;
            colcnt[u] = 0;
        }
    }

    for (int col = 1; col <= n; ++col) {
        cout << ans[col] << ' ';
    }
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}