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
// Created: 2026-04-02 19:41

constexpr ll INF = 4e18;
constexpr ll LINF = 4e18;

#define FILENAME "175"

using namespace std;
using pii = pair<long, long>;
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

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

vector<pll> g[MAXN];
vector<ll> dist(MAXN, LINF);
vector<ll> dag[MAXN];
vector<ll> topo;
vector<int> deg(MAXN, 0);

void dijkstra(int s) {
    pqueue<pll, vector<pll>, greater<pll>> pq;
    pq.emplace(0, s);
    dist[s] = 0;
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        g[a].pb({b, c});
        // g[b].pb({a, c});
    }
    dijkstra(1);
    ll res1 = dist[n];
    ll res2, res3, res4;
    //build DAG
    for (int i = 1; i <= n; i++) {
        for (auto &[v, w] : g[i]) {
            if (dist[v] == dist[i] + w) {
                dag[i].pb(v);
                ++deg[v];
            }
        }
    }
    // toposort
    {
        vector<int> deg2 = deg;
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (deg2[i] == 0) {
                q.emplace(i);
            }
        }
        while (q.size()) {
            int u = q.front(); q.pop();
            topo.pb(u);
            for (auto &v : dag[u]) {
                if (--deg2[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
    //res2
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (auto &v : topo) {
            for (auto &u : dag[v]) {
                dp[u] = (dp[u] + dp[v]) % MOD;
            }
        }
        res2 = dp[n] % MOD;
    }
    //res3
    {
        vector<ll> dp(n + 1, LINF);
        dp[1] = 0;
        for (auto &v : topo) {
            for (auto &u : dag[v]) {
                dp[u] = min(dp[u], dp[v] + 1);
            }
        }
        res3 = dp[n];
    }
    //res4
    {
        vector<ll> dp(n + 1, -LINF);
        dp[1] = 0;
        for (auto &v : topo) {
            for (auto &u : dag[v]) {
                dp[u] = max(dp[u], dp[v] + 1);
            }
        }
        res4 = dp[n];
    }

    cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res4;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}