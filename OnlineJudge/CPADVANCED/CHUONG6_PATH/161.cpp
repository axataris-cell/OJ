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
// Created: 2026-03-27 10:04

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "161"

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

const int MAXN = 505;

int adj[MAXN][MAXN];
vector<pii> g[MAXN];
vector<int> dist(MAXN, INF);

void dijkstra(int s) {
    pqueue<pii, vector<pii>, greater<pii>> pq;

    pq.emplace(0, s);
    dist[s] = 0;

    while (pq.size()) {
        pii x = pq.top(); pq.pop();
        int u = x.second;
        int d = x.first;

        if (d > dist[u]) continue;

        for (const auto &[v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

void testcase() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j]) {
                g[i].pb({j, adj[i][j]});
            }
        }
    }
    int res = INF;
    int best = -1;
    for (int i = 1; i <= n; i++) {
        for (int u = 1; u <= n; u++) dist[u] = INF;
        dijkstra(i);
        int mx = 0;
        for (int u = 1; u <= n; u++) mx = max(dist[u], mx);

        if (mx < res) {
            res = mx;
            best = i;
        }
    }
    for (int u = 1; u <= n; u++) dist[u] = INF;
    dijkstra(best);
    vector<int> par(MAXN, -1);
    for (int i = 1; i <= n; i++) {
        for (const auto &[v, w] : g[i]) {
            if (dist[v] == dist[i] + w) {
                par[v] = i;
            }
        }
    }
    vector<int> path[MAXN];
    for (int u = 1; u <= n; u++) {
        if (u == best) continue;
        int cur = u;
        while (cur != -1) {
            path[u].pb(cur);
            cur = par[cur];
        }
        // reverse(all(path[u]));
    }
    cout << best << ' ' << res << el;
    for (int i = 1; i <= n; i++) {
        if (i == best) continue;
        for (auto x : path[i]) cout << x << ' ';
        cout << el;
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