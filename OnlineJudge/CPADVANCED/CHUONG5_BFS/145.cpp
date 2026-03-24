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
// Created: 2026-03-24 20:04

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "145"

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
vector<int> dist(MAXN, -1);
vector<int> par(MAXN, -1);
bool vis[MAXN];

void bfs(int s) {
    queue<int> q;

    q.push(s);
    vis[s] = true;
    dist[s] = 0;

    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                par[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    bfs(1);
    
    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << el;
        return;
    }

    int cur = n;
    vector<int> path;
    while (cur != -1) {
        path.pb(cur);
        cur = par[cur];
    }
    reverse(all(path));

    cout << path.size() << el;
    for (auto x : path) cout << x << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}