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
// Created: 2026-07-03 08:09

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "DinhHuongGiaoThong"

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

const int MAXN = 2e5 + 5;

vector<int> ga[MAXN];
int indeg[MAXN];
int pos[MAXN];

void testcase() {
    int n, m; 
    if (!(cin >> n >> m)) return;

    for (int i = 1; i <= n; i++) {
        ga[i].clear();
        indeg[i] = 0;
        pos[i] = 0;
    }

    vector<pii> undir_edges;

    for (int i = 1; i <= m; i++) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 1) {
            ga[u].pb(v);
            indeg[v]++;
        } else {
            undir_edges.pb({u, v});
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }
    
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        pos[u] = ++cnt;
        for (int v : ga[u]) {
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    
    if (cnt < n) {
        cout << "NO" << el;
        return;
    }
    
    cout << "YES" << el;
    for (auto edge : undir_edges) {
        int u = edge.fi, v = edge.se;
        if (pos[u] < pos[v]) {
            cout << u << " " << v << el;
        } else {
            cout << v << " " << u << el;
        }
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