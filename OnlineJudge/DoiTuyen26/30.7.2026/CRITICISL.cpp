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
    // Created: 2026-07-30 14:17

    constexpr int INF = 2e9;
    constexpr ll LINF = 4e18;

    #define FILENAME "criticisl"

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
        if (FILE *f = fopen(FILENAME".inp", "r")) {
            fclose(f);
            freopen(FILENAME".inp", "r", stdin);
            freopen(FILENAME".out", "w", stdout);
        }
    }

    const int MAXN = 2e5 + 5;

    struct Edge {
        int v, h, id;
    };

    vector<Edge> g[MAXN];

    int visbfs[MAXN];
    int bfsCount = 0;
    bool bfs(int h, int &n) {
        queue<int> q;
        ++bfsCount;
        q.push(1);
        visbfs[1] = bfsCount;

        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto &[v, w, id] : g[u]) {
                if (visbfs[v] == bfsCount || w < h) continue;
                visbfs[v] = bfsCount;
                q.push(v);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (visbfs[i] != bfsCount) return false;
        }
        return true;
    }

    int tin[MAXN];
    int low[MAXN];
    bool joint[MAXN];
    int timeDfs = 0;

    int cnt = 0;

    void dfs(int u, int parEdge, int h) {
        int child = 0;
        tin[u] = low[u] = ++timeDfs;
        for (auto &[v, w, id] : g[u]) {
            if (id == parEdge || w < h) continue;
            if (!tin[v]) {
                dfs(v, id, h);
                low[u] = min(low[u], low[v]);
                child++;
                if (parEdge == -1) {
                    if (child > 1) {
                        joint[u] = true;
                    }
                }
                else if (low[v] >= tin[u]) joint[u] = true;
            } else low[u] = min(low[u], tin[v]);
        }
    }

    void testcase() {
        int n, m; cin >> n >> m;
        int k; cin >> k;
        for (int i = 1; i <= m; i++) {
            int a, b; cin >> a >> b;
            int h; cin >> h;
            g[a].pb({b, h, i});
            g[b].pb({a, h, i});
        }
        // tim chan tren lam do thi khong lien thong
        int R = -1;
        {
            int l = 1, r = 1e9;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (bfs(mid, n)) {
                    l = mid + 1;
                    R = mid;
                } else r = mid - 1;
            }
        }
        int res = -1;
        int L = 0;
        while (L <= R) {
            cnt = 0;
            for (int i = 1; i <= n; i++) {
                joint[i] = false;
                tin[i] = 0;
                low[i] = 0;
            }
            timeDfs = 0;
            int mid = (L + R) / 2;
            dfs(1, -1, mid);
            for (int i = 1; i <= n; i++) {
                if (joint[i]) ++cnt;
            }
            if (cnt >= k) {
                res = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }

        if (res == -1) {
            cout << "-1 0";
            return;
        }

        // chay not lan cuoi :)
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            joint[i] = false;
            tin[i] = 0;
            low[i] = 0;
        }
        timeDfs = 0;
        dfs(1, -1, res);
        for (int i = 1; i <= n; i++) {
            if (joint[i]) ++cnt;
        }

        cout << max(res - 1, 0) << ' ' << cnt << el;
        for (int i = 1; i <= n; i++) {
            if (joint[i]) cout << i << ' ';
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