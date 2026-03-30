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
// Created: 2026-03-28 15:18

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "166"

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

const int MAXN = 1e2 + 5;

int adj[MAXN][MAXN];
int cost[MAXN];
vector<pii> g[MAXN];

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if (adj[i][j] != -1) {
                g[i].pb({j, adj[i][j]});
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int s, t; cin >> s >> t;
        vector<int> dist(n + 1, INF);
        vector<int> par(n + 1, -1);

        pqueue<pii, vector<pii>, greater<pii>> pq;

        pq.emplace(0, s);
        dist[s] = 0;

        while (pq.size()) {
            pii x = pq.top(); pq.pop();
            int u = x.second;
            int d = x.first;

            if (d > dist[u]) continue;

            for (pii y : g[u]) {
                int v = y.first;
                int w = y.second;
                if (v != s && v != t) w += cost[v];
                
                if (dist[v] > dist[u] + w) {
                    par[v] = u;
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int cur = t;
        vector<int> path;
        while (cur != -1) {
            path.pb(cur);
            cur = par[cur];
        }
        reverse(all(path));

        for (auto x : path) cout << x << ' ';
        cout << el;
        cout << dist[t] << el;
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