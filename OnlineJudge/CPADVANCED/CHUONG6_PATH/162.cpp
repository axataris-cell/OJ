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
// Created: 2026-03-27 13:58

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "162"

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
#define int long long

const int MAXN = 1e5 + 5;

vector<pll> g[MAXN];
vector<char> par(MAXN);
vector<int> dist(MAXN, LINF);
vector<char> start;

void dijkstra() {
    pqueue<pll, vector<pll>, greater<pll>> pq;

    for (auto u : start) {
        pq.emplace(0, u);
        dist[u] = 0;
        par[u] = u;
    }

    while (pq.size()) {
        pii x = pq.top(); pq.pop();
        int u = x.second;
        int d = x.first;

        if (d > dist[u]) continue;

        for (pii y : g[u]) {
            int v = y.first;
            int w = y.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = par[u];
                pq.emplace(dist[v], v);
            } else if (dist[v] == dist[u] + w) par[v] = min((int)par[v], (int)par[u]);
        }
    }
}

void testcase() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        char a, b; cin >> a >> b;
        int w; cin >> w;
        g[a].pb({b, w});
        g[b].pb({a, w});
        if (a >= 'A' && a <= 'Z') start.pb(a);
    }
    sort(all(start));
    start.erase(unique(all(start)), start.end());
    dijkstra();

    // char res = 'Z';
    // for (auto y : g['z']) {
    //     int u = y.first;
    //     int w = y.second;
    //     if (dist['z'] == dist[u] + w) {
    //         res = min((int)res, (int)par[u]);
    //     }
    // }

    cout << par['z'] << ' ' << (dist['z'] == INF ? -1 : dist['z']);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}