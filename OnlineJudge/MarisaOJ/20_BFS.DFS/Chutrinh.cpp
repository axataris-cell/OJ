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
// Created: 2026-04-13 20:36

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Chutrinh"

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
vector<int> deg(MAXN, 0);
void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        ++deg[b];
    }
    vector<int> topo;
    queue<int> q;
    for (int i = 1; i <= n; i++) { 
        if (deg[i] == 0) q.emplace(i);
    }
    while (q.size()) {
        int u = q.front(); q.pop();
        topo.pb(u);
        for (int v : g[u]) {
            if (deg[v] == 0) continue;
            if (--deg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    cout << (topo.size() < n ? "YES" : "NO");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}