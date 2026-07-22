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
    // Created: 2026-07-18 15:23

    constexpr int INF = 2e9;
    constexpr ll LINF = 4e18;

    #define FILENAME "ColorQuery"

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

    const int MAXN = 1e5 + 5;

    vector<int> color(MAXN, 0);

    struct DSU {
        vector<int> par, sz;
        vector<map<int, int>> mp;

        DSU(int n) : sz(n), par(n), mp(n) {}

        void make(int u) {
            sz[u] = 1;
            par[u] = u;
            mp[u][color[u]]++;
        }

        int find(int u) {
            return (u == par[u] ? u : par[u] = find(par[u]));
        }

        void unite(int u, int v) {
            u = find(u);
            v = find(v);
            if (u == v) return;
            if (sz[u] < sz[v]) swap(u, v);
            sz[u] += sz[v];
            par[v] = u;
            for (auto &[k, v] : mp[v]) {
                mp[u][k] += v;
            }
        }
    };

    void testcase() {
        int n, q; cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> color[i];
        }

        DSU dsu(n + 1);
        for (int i = 1; i <= n; i++) {
            dsu.make(i);
        }

        while (q--) {
            int t ,l, r; cin >> t >> l >> r;
            if (t == 1) {
                dsu.unite(l, r);
            } else {
                int x = dsu.find(l);
                cout << dsu.mp[x][r] << el;
            }
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