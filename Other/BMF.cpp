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
// Created: 2026-04-16 21:35

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "BMF"

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

const int MAXN = 1e5 + 5;

struct Edge {
    int u, v, w;
};
vector<Edge> edges;
vector<int> dist(MAXN, INF);

void testcase() {
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t;
    for (int i = 1; i <= m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges.pb({a, b, w});
        edges.pb({b, a, w});
    }
    
    dist[s] = 0;
    bool ncyclic = false;
    for (int i = 1; i <= n; i++) {
        bool changed = false;
        for (const auto &e : edges) {
            if (dist[e.u] == INF) continue;
            if (dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
                if (i == n) {
                    ncyclic = true;
                    break;
                }
            }
        }
        if (!changed) break;
        if (ncyclic) break;
    }

    cout << ((ncyclic || dist[t] == INF) ? -1 : dist[t]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}