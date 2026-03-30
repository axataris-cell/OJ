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
// Created: 2026-03-30 08:33

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "173"

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

const int MAXN = 105;

vector<pii> g[MAXN];

int pre_node[16][MAXN];
int pre_mask[16][MAXN];
int from_node[16][MAXN];

void dijkstra(vector<int> &dist, vector<int> start, int mask) {
    pqueue<pii, vector<pii>, greater<pii>> pq;
    for (int s : start) pq.emplace(dist[s], s);
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre_node[mask][v] = u;
                pre_mask[mask][v] = mask;
                pq.emplace(dist[v], v);
            }
        }
    }
}

set<pii> edges;

void trace(int mask, int u) {
    if (mask == 0 || u == 0) return;

    if ((mask & (mask - 1)) == 0) {
        while (u && pre_node[mask][u]) {
            int p = pre_node[mask][u];
            edges.insert({min(p, u), max(p, u)});
            u = p;
        }
        return;
    }

    if (pre_mask[mask][u] == mask) {
        int p = pre_node[mask][u];
        if (p == 0) return;
        edges.insert({min(p, u), max(p, u)});
        trace(mask, p);
        return;
    }

    int sub = pre_mask[mask][u];
    if (sub == 0 || sub == mask) return;
    int other = mask ^ sub;

    trace(sub, u);
    trace(other, u);
}

void testcase() {
    int n; cin >> n;
    int target[4];
    for (int i = 0; i < 4; i++) cin >> target[i];
    int u, v, c;
    while (cin >> u >> v >> c) {
        g[u].pb({v, c});
        g[v].pb({u, c});
    }

    vector<vector<int>> dp(16, vector<int>(n + 1, INF));

    for (int i = 0; i < 16; i++)
        for (int j = 0; j <= n; j++) {
            pre_node[i][j] = 0;
            pre_mask[i][j] = 0;
        }

    for (int i = 0; i < 4; i++) {
        dp[1 << i][target[i]] = 0;
        dijkstra(dp[1 << i], {target[i]}, 1 << i);
    }

    for (int mask = 1; mask < 16; mask++) {
        if ((mask & (mask - 1)) == 0) continue;

        for (int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask) {
            int other = mask ^ sub;
            for (int i = 1; i <= n; i++) {
                if (dp[mask][i] > dp[sub][i] + dp[other][i]) {
                    dp[mask][i] = dp[sub][i] + dp[other][i];
                    pre_mask[mask][i] = sub;
                    pre_node[mask][i] = 0;
                }
            }
        }

        vector<int> start;
        for (int i = 1; i <= n; i++)
            if (dp[mask][i] < INF) start.pb(i);

        dijkstra(dp[mask], start, mask);
    }

    int ans = INF;
    int best = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[15][i] < ans) {
            ans = dp[15][i];
            best = i;
        }
    }

    cout << ans << el;

    trace(15, best);

    for (auto [x, y] : edges) cout << x << " " << y << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1;
    while (t--) testcase();

    return 0;
}