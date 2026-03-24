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
// Created: 2026-03-24 15:56

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "133"

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

vector<int> g[MAXN];
vector<int> dist(MAXN, 0);

void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        dist[v] = dist[u] + 1;
        dfs(v, u);
    }
} 
void testcase() {
    int n, c; cin >> n >> c;
    for (int i = 1; i <= c; i++) {
        int a, b, k; cin >> a >> b >> k;
        g[a].push_back(b);
        g[a].push_back(k);
        g[b].push_back(a);
        g[k].push_back(a);
    }
    g[0].push_back(1);
    g[1].push_back(0);
    dfs(0, 0);

    for (int i = 1; i <= n; i++) cout << dist[i] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}