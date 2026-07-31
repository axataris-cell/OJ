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
// Created: 2026-07-21 09:15

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "balloon"

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

vector<pair<int, ll>> g[MAXN];
vector<pair<int, ll>> SP[MAXN];

void testcase() {
    int n, m; cin >> n >> m;
    map<pii, ll> mp;
    for (int i = 1; i <= m; i++) {
        int a, b; ll c; cin >> a >> b >> c;
        ll w = mp[{a, b}];
        if (w > c || w == 0) {
            mp[{a, b}] = mp[{b, a}] = c;
        }
    }
    for (auto &[k, v] : mp) {
        auto &[a, b] = k;
        g[a].pb({b, v});
    }

    pqueue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(MAXN, LINF);
    dist[0] = 0;
    pq.emplace(0, 0);

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

    vector<int> deg(n + 1, 0);

    for (int u = 0; u <= n; u++) {
        for (auto &[v, w] : g[u]) {
            if (dist[v] == dist[u] + w) {
                SP[u].pb({v, w});
                ++deg[v];
            }
        }
    }

    vector<ll> dp(n + 1, -LINF);
    {
        vector<int> topo;
        queue<int> q;
        q.emplace(0);
        while (q.size()) {
            int u = q.front(); q.pop();
            topo.pb(u);
            for (auto &[v, w] : SP[u]) {
                if (--deg[v] == 0) {
                    q.push(v);
                }
            }
        }
        dp[0] = 0;
        for (auto u : topo) {
            for (auto &[v, w] : SP[u]) {
                dp[v] = max(dp[v], w);
            }
        }
    }

    ll res = 0;
    for (int i = 0; i <= n; i++) res += dp[i];

    cout << m - n << ' ' << res;
}

/*
4 6
0 1 5 
0 2 3
1 3 4
2 3 6
3 4 2
2 4 10
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}