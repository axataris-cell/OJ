#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "MST"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;
struct Edge {
    int u, v, w;
};
struct DSU {
    vector<int> par;
    DSU(int n) : par(n + 1) {
        for(int i = 1; i <= n; i++) par[i] = i;
    }
    int find(int u) {
        return (par[u] == u ? u : par[u] = find(par[u]));
    }
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        par[v] = u;
        return true;
    }
};
int power(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
int modInverse(int n) {
    return power(n, MOD - 2);
}
struct TreeLCA {
    int n;
    vector<int> depth;
    vector<int> up, min_pos, min_neg, max_pos, max_neg;

    struct TreeEdge {
        int to;
        long long w;
    };
    vector<vector<TreeEdge>> adj;

    TreeLCA(int n) : n(n) {
        depth.assign(n + 1, 0);
        int sz = (n + 1) * LOG;
        up.assign(sz, 0);
        min_pos.assign(sz, INF);
        min_neg.assign(sz, INF);
        max_pos.assign(sz, -1);
        max_neg.assign(sz, -1);
        adj.resize(n + 1);
    }

    inline int idx(int u, int k) const {
        return u * LOG + k;
    }

    void add(int u, int v, long long w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void dfs(int u, int p, int d) {
        depth[u] = d;
        up[idx(u, 0)] = p;
        for (auto& e : adj[u]) {
            int v = e.to;
            long long w = e.w;
            if (v != p) {
                int abs_w = abs(w);
                if (w > 0) {
                    min_pos[idx(v, 0)] = max_pos[idx(v, 0)] = abs_w;
                } else if (w < 0) {
                    min_neg[idx(v, 0)] = max_neg[idx(v, 0)] = abs_w;
                }
                dfs(v, u, d + 1);
            }
        }
    }

    void build(int root = 1) {
        dfs(root, root, 0);
        for (int k = 1; k < LOG; k++) {
            for (int i = 1; i <= n; i++) {
                int par = up[idx(i, k - 1)];
                up[idx(i, k)] = up[idx(par, k - 1)];
                min_pos[idx(i, k)] = min(min_pos[idx(i, k - 1)], min_pos[idx(par, k - 1)]);
                min_neg[idx(i, k)] = min(min_neg[idx(i, k - 1)], min_neg[idx(par, k - 1)]);
                max_pos[idx(i, k)] = max(max_pos[idx(i, k - 1)], max_pos[idx(par, k - 1)]);
                max_neg[idx(i, k)] = max(max_neg[idx(i, k - 1)], max_neg[idx(par, k - 1)]);
            }
        }
    }

    int lcamn(int u, int v, bool need_pos) {
        int ans = INF;
        if (depth[u] < depth[v]) swap(u, v);

        for (int k = LOG - 1; k >= 0; k--) {
            if (depth[u] - (1 << k) >= depth[v]) {
                ans = min(ans, need_pos ? min_pos[idx(u, k)] : min_neg[idx(u, k)]);
                u = up[idx(u, k)];
            }
        }
        if (u == v) return ans;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[idx(u, k)] != up[idx(v, k)]) {
                ans = min(ans, need_pos ? min_pos[idx(u, k)] : min_neg[idx(u, k)]);
                ans = min(ans, need_pos ? min_pos[idx(v, k)] : min_neg[idx(v, k)]);
                u = up[idx(u, k)];
                v = up[idx(v, k)];
            }
        }
        ans = min(ans, need_pos ? min_pos[idx(u, 0)] : min_neg[idx(u, 0)]);
        ans = min(ans, need_pos ? min_pos[idx(v, 0)] : min_neg[idx(v, 0)]);
        return ans;
    }

    int lcamx(int u, int v, bool need_pos) {
        int ans = -1;
        if (depth[u] < depth[v]) swap(u, v);

        for (int k = LOG - 1; k >= 0; k--) {
            if (depth[u] - (1 << k) >= depth[v]) {
                ans = max(ans, need_pos ? max_pos[idx(u, k)] : max_neg[idx(u, k)]);
                u = up[idx(u, k)];
            }
        }
        if (u == v) return ans;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[idx(u, k)] != up[idx(v, k)]) {
                ans = max(ans, need_pos ? max_pos[idx(u, k)] : max_neg[idx(u, k)]);
                ans = max(ans, need_pos ? max_pos[idx(v, k)] : max_neg[idx(v, k)]);
                u = up[idx(u, k)];
                v = up[idx(v, k)];
            }
        }
        ans = max(ans, need_pos ? max_pos[idx(u, 0)] : max_neg[idx(u, 0)]);
        ans = max(ans, need_pos ? max_pos[idx(v, 0)] : max_neg[idx(v, 0)]);
        return ans;
    }
};

void testcase() {
    int n, m; cin >> n >> m;

    vector<Edge> nz;
    bool hsz = false;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        if (w == 0) {
            if (u != v) hsz = true;
        } else {
            nz.push_back({u, v, w});
        }
    }
    //0
    {
        DSU dsu(n);
        int comp = n;
        for (const auto& e : nz) {
            if (dsu.unite(e.u, e.v)) {
                comp--;
            }
        }

        if (comp > 1) {
            cout << 0;
            return;
        }
    }


    //<0
    auto desc = nz;
    sort(desc.begin(), desc.end(), [](const Edge& a, const Edge& b) {
        return abs(a.w) > abs(b.w);
    });

    DSU dsu_max(n);
    vector<Edge> temp, thua;
    int negcnt = 0;

    for (const auto& e : desc) {
        if (dsu_max.unite(e.u, e.v)) {
            temp.push_back(e);
            if (e.w < 0) negcnt++;
        } else {
            thua.push_back(e);
        }
    }

    int p = 1;
    for (const auto& e : temp) {
        p = (p * (abs(e.w) % MOD)) % MOD;
    }

    if (negcnt % 2 != 0) {
        int ans = (MOD - p) % MOD;
        cout << ans;
        return;
    }

    //swap
    TreeLCA lca_max(n);
    for (const auto& e : temp) {
        lca_max.add(e.u, e.v, e.w);
    }
    lca_max.build(1);

    int best = -1, bestw = -1;
    for (const auto& e : thua) {
        bool t = (e.w < 0);
        int can = lca_max.lcamn(e.u, e.v, t);

        if (can != INF) {
            if (best == -1 || abs(e.w) * bestw > best * can) {
                best = abs(e.w);
                bestw = can;
            }
        }
    }

    if (best != -1) {
        int sw = (p * modInverse(bestw) % MOD) * (best % MOD) % MOD;
        int ans = (MOD - sw) % MOD;
        cout << ans;
        return;
    }

    //0
    if (hsz) {
        cout << 0;
        return;
    }

    //>0
    auto asc = nz;
    sort(asc.begin(), asc.end(), [](const Edge& a, const Edge& b) {
        return abs(a.w) < abs(b.w);
    });

    DSU dsu_min(n);
    vector<Edge> temp2;
    vector<Edge> thua2;
    int cntmin = 0;

    for (const auto& e : asc) {
        if (dsu_min.unite(e.u, e.v)) {
            temp2.push_back(e);
            if (e.w < 0) cntmin++;
        } else {
            thua2.push_back(e);
        }
    }

    int p2 = 1;
    for (const auto& e : temp2) {
        p2 = (p2 * (abs(e.w) % MOD)) % MOD;
    }

    if (cntmin % 2 == 0) {
        cout << p2;
        return;
    }

    TreeLCA lca_min(n);
    for (const auto& e : temp2) {
        lca_min.add(e.u, e.v, e.w);
    }
    lca_min.build(1);

    best = -1;
    bestw = -1;

    for (const auto& e : thua2) {
        bool t = (e.w < 0);
        int can = lca_min.lcamx(e.u, e.v, t);

        if (can != -1) {
            if (best == -1 || abs(e.w) * bestw < best * can) {
                best = abs(e.w);
                bestw = can;
            }
        }
    }

    int res = (p2 * modInverse(bestw) % MOD) * (best % MOD) % MOD;
    cout << res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}