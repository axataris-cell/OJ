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
// Created: 2026-05-04 10:18

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "1"

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
vector<vector<int>> dist(2, vector<int>(MAXN, LINF));
struct State {
    int d, u, k;
};

struct Comp {
    bool operator()(const State &x, const State &y) const {
        return x.d > y.d;
    }
};

void dijkstra(int s) {
    pqueue<State, vector<State>, Comp> pq;
    pq.push({0, s, 1});
    dist[1][s] = 0;
    while (pq.size()) {
        auto [d, u, k] = pq.top(); pq.pop();
        if (d > dist[k][u]) continue;
        for (const auto &[v, w] : g[u]) {
            if (dist[k][v] > dist[k][u] + w) {
                dist[k][v] = dist[k][u] + w;
                pq.push({dist[k][v], v, k});
            }
            if (k & 1) {
                if (dist[0][v] > dist[k][u]) {
                    dist[0][v] = dist[k][u];
                    pq.push({dist[0][v], v, 0});
                }
            }
        }
    }
}
void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        int w; cin >> w;
        g[a].pb({b, w});
        g[b].pb({a, w});
    }
    dijkstra(1);
    cout << (dist[0][n] == LINF ? -1 : dist[0][n]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}