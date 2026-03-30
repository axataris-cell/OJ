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
// Created: 2026-03-28 22:49

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "172"

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

const int MAXN = 25;
vector<pii> g[MAXN];

void testcase() {
    int n, k; cin >> n >> k;
    for (int u = 1; u <= k; u++) {
        int i, j, m; cin >> i >> j >> m;
        for (int it = 1; it <= m; it++) {
            int t; cin >> t;
            g[i].pb({j, t});
            g[j].pb({i, t});
        }
    }
    for (int i = 1; i <= n; i++) sort(all(g[i]), [](const pii &x, const pii &y) {return x.second < y.second;});
    vector<int> dist(n + 1, INF);
    pqueue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        int div = d / 100;
        for (auto &[v, t] : g[u]) {
            int w;
            if (d > t + div * 100) {
                w = t + (div + 1) * 100 - d;
            } else {
                w = t + div * 100 - d;
            }
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    bool ok = true;
    int res = -INF;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            ok = false;
            break;
        } else res = max(res, dist[i]);
    }
    cout << (ok ? res : -1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}