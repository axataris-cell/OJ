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
// Created: 2026-03-24 20:08

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "146"

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

const int MAXN = 2505;

vector<int> g[MAXN];
bool vis[MAXN];

int shortest_cycle(int n) {

    int res = INF;

    for (int start = 1; start <= n; start++) {

        vector<int> dist(n + 1, -1);
        vector<int> par(n + 1, -1);

        queue<int> q;

        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (int v : g[u]) {

                if (dist[v] == -1) {

                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);

                }
                else if (par[u] != v) {

                    res = min(res, dist[u] + dist[v] + 1);
                }
            }
        }
    }

    return res == INF ? -1 : res;
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    cout << shortest_cycle(n);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}