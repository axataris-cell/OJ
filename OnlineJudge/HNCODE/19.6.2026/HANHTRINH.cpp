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
// Created: 2026-06-19 08:26

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "HANHTRINH"

using namespace std;
using pii = pair<int, int>;
using pll = pair<int, int>;

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

void testcase() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(k);
    vector<int> special_mask(n + 1, 0);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        special_mask[a[i]] |= (1 << i);
    }

    vector<vector<pll>> adj(n + 1);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        deg[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) q.push(i);
    }

    vector<int> topo(n + 1, 0); // id topo
    vector<int> kahn; // day topo
    kahn.reserve(n);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo[u] = kahn.size();
        kahn.pb(u);
        for (auto& edge : adj[u]) {
            if (--deg[edge.fi] == 0) {
                q.push(edge.fi);
            }
        }
    }

    vector<int> S;
    S.pb(1);
    S.pb(n);
    for (int i = 0; i < k; ++i) S.pb(a[i]);

    sort(all(S));
    S.erase(unique(all(S)), S.end());

    sort(all(S), [&](int u, int v) {
        return topo[u] < topo[v];
    });

    int c = S.size();

    vector<vector<int>> dist(c, vector<int>(c, LINF));
    for (int i = 0; i < c; ++i) {
        vector<int> d(n + 1, LINF);
        int s = S[i];
        d[s] = 0;
        
        for (int rank = topo[s]; rank < n; ++rank) {
            int u = kahn[rank];
            if (d[u] != LINF) {
                for (auto & [v, w] : adj[u]) {
                    if (d[u] + w < d[v]) {
                        d[v] = d[u] + w;
                    }
                }
            }
        }
        for (int j = i + 1; j < c; ++j) {
            dist[i][j] = d[S[j]];
        }
    }

    
    int start = -1, end = -1;
    for (int i = 0; i < c; ++i) {
        if (S[i] == 1) start = i;
        if (S[i] == n) end = i;
    }

    if (start == -1 || end == -1 || start > end) {
        cout << -1 << el;
        return;
    }

    vector<vector<int>> dp(c, vector<int>(1 << k, LINF));
    dp[start][special_mask[1]] = 0;

    for (int i = start; i < c; ++i) {
        for (int mask = 0; mask < (1 << k); ++mask) {
            if (dp[i][mask] != LINF) {
                for (int j = i + 1; j < c; ++j) {
                    if (dist[i][j] != LINF) {
                        int next_mask = mask | special_mask[S[j]];
                        dp[j][next_mask] = min(dp[j][next_mask], dp[i][mask] + dist[i][j]);
                    }
                }
            }
        }
    }

    int ans = dp[end][(1 << k) - 1];

    cout << (ans == LINF ? -1 : ans);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}

