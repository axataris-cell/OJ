#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-18 11:09

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

#define int long long

const int MAXN = 2e5 + 5;

vector<pll> g[MAXN];
vector<int> par(MAXN, 0);
vector<int> dist(MAXN, LINF);

void dijkstra(int s) {
    pqueue<pll, vector<pll>, greater<pll>> pq; // w - v;

    pq.emplace(0, s);
    dist[s] = 0;

    while (pq.size()) {
        pll x = pq.top(); pq.pop();
        int u = x.second;
        int d = x.first;

        if (d > dist[u]) continue;

        for (pll y : g[u]) {
            int v = y.first;
            int w = y.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
}

void buildDAG() {
    
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int k; cin >> k;
    vector<int> path(k + 1, 0);
    for (int i = 1; i <= k; i++) cin >> path[i];

    dijkstra(path[k]); // đường đi từ điểm cuối tới mọi đỉnh :D
    buildDAG();

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}