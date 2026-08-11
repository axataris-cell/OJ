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
    // Created: 2026-08-10 08:26

    constexpr int INF = 2e9;
    constexpr ll LINF = 4e18;

    #define FILENAME "A"

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

    const int MAXN = 2e5 + 5;

    vector<int> g[MAXN];
    bool isCentroid[MAXN];
    int sz[MAXN];

    void dfs(int u, int p, int treesz) {
        sz[u] = 1;
        int mxsz = 0;
        for (int v : g[u]) {
            if (v == p) continue;
            dfs(v, u, treesz);
            sz[u] += sz[v];
            mxsz = max(mxsz, sz[v]);
        }
        mxsz = max(mxsz, treesz - sz[u]);
        if (mxsz <= treesz / 2) isCentroid[u] = true;
    }

    void testcase() {
        int n; cin >> n;
        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(1, 1, n);
        for (int i = 1; i <= n; i++) {
            if (isCentroid[i]) {
                cout << i;
                return;
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