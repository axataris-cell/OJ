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
// Created: 2026-03-24 15:51

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "132"

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

bool ok = true;

vector<int> g[MAXN];
vector<int> color(MAXN, 0);
bool vis[MAXN];

void bfs(int s) {
    queue<int> q;

    q.push(s);
    vis[s] = true;
    color[s] = 0;

    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                color[v] = color[u] ^ 1;
                q.push(v);
            } else {
                if (color[v] != color[u] ^ 1) {
                    ok = false;
                    return;
                }
            }
        }
    }
}
void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) bfs(i);
    }

    if (!ok) {
        cout << "IMPOSSIBLE" << el;
        return;
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] + 1 << ' ';
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