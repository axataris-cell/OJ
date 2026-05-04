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
// Created: 2026-05-04 19:51

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "2"

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
vector<int> vis(MAXN, 0); // 2 -> out, 1 -> dang tham
vector<int> par(MAXN, 0);

vector<int> res;
bool cyclic = false;

void dfs(int u) {
    vis[u] = 1;
    for (const int &v : g[u]) {
        if (cyclic) break;
        if (vis[v] == 0) {
            par[v] = u;
            dfs(v);
        } else if (vis[v] == 1) {
            cyclic = true;
            res.pb(u);
            return;
        }
    }
    if (cyclic) {
        res.pb(u);
        return;
    }
    vis[u] = 2;
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
    }   
    dfs(1);
    if (!cyclic) {
        cout << "NO" << el;
        return;
    }
    cout << "YES" << el;
    for (auto v : res) cout << v << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}