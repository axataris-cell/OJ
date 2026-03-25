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
// Created: 2026-03-25 20:39

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "151"

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

const int MAXN = 1e4 + 5;

vector<int> g[MAXN]; 
bool boxes[MAXN];
vector<int> order;
vector<int> dist(MAXN, 0);
vector<int> par(MAXN, 0);
bool vis[MAXN];

ll res = 0;

void bfs(int s) {
    queue<int> q;

    q.push(s);
    vis[s] = true;
    dist[s] = 0;

    while (q.size()) {
        int u = q.front(); q.pop();
        if (boxes[u]) {
            res += dist[u];
            order.pb(u);
        }
        for (int v : g[u]) {
            if (!vis[v]) {
                par[v] = u;
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void testcase() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        boxes[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[b].pb(a);
    }
    bfs(1);

    // for (auto u : order) debug(u);

    vector<pii> path;
    for (auto u : order) {
        int cur = u;
        while (par[cur] != 0) {
            path.pb({cur, par[cur]});
            cur = par[cur];
        }
    }
    cout << path.size() << el;
    for (auto x : path) cout << x.fi << ' ' << x.se << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}