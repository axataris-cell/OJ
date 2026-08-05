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
// Created: 2026-08-05 18:56

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "bruh"

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
const int MAXM = 1e6 + 5;

struct Edge {
    int v, id;
};

vector<Edge> g[MAXN];
vector<Edge> reversed[MAXN];
bool r1[MAXM], r2[MAXM];
bool reachable[MAXM];

vector<int> res;

bool visited[MAXN];

bool dfs(int u, int t) {
    visited[u] = true;
    res.pb(u);
    if (u == t) return true;
    sort(all(g[u]), [](const Edge &x, const Edge &y) {
        return x.v < y.v;
    });
    for (auto &[v, id] : g[u]) {
        if (!reachable[id]) continue;
        if (visited[v]) continue;
        if (dfs(v, t)) {
            return true;
        }
    }
    visited[u] = false; 
    return false;
}

void testcase() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb({b, i});
        reversed[b].pb({a, i});
    }

    {
        queue<int> q;
        vector<bool> vis(MAXN, false);

        q.push(s);
        vis[s] = true;

        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto &[v, id] : g[u]) {
                if (vis[v]) r1[id] = true;
                else {
                    vis[v] = true;
                    r1[id] = true;
                    q.push(v);
                }
            }
        }
    }

    {
        queue<int> q;
        vector<bool> vis(MAXN, false);

        q.push(t);
        vis[t] = true;

        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto &[v, id] : reversed[u]) {
                if (vis[v]) r2[id] = true;
                else {
                    vis[v] = true;
                    r2[id] = true;
                    q.push(v);
                }
            }
        }
    }
    
    for (int i = 1; i <= m; i++) {
        reachable[i] = r1[i] && r2[i];
    }

    dfs(s, t);

    for (auto u : res) cout << u << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}