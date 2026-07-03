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
// Created: 2026-07-03 07:57

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "KhoiPhucDiemSo"

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

vector<int> g[MAXN];

void testcase() {
    int n, m; cin >> n >> m;
    vector<int> deg(n + 1, 0);
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b; // a > b
        g[b].pb(a);
        ++deg[a];
    }
    vector<int> topo;
    {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                ++res[i];
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.pb(u);
            for (int v : g[u]) {
                if (--deg[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
    if (topo.size() != n) {
        cout << -1;
        return;
    }
    for (auto u : topo) {
        for (auto v : g[u]) {
            res[v] = max(res[v], res[u] + 1);
        }
    }
    // for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    // return;
    cout << *max_element(all(res));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}