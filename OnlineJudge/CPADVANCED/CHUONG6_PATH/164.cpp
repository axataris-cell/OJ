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
// Created: 2026-03-27 17:09

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "164"

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

const int MAXN = 1e3 + 5;

vector<pii> g[MAXN];
vector<int> dist(MAXN, INF);
vector<int> bakudan(MAXN, 0);

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
            if (bakudan[v] != 0 && bakudan[v] <= dist[u] + w) {
                continue;
            }
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

void testcase() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++) {
        cin >> bakudan[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c; 
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    dijkstra(s);

    cout << (dist[t] == INF ? -1 : dist[t]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}