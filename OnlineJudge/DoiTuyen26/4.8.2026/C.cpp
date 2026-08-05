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
// Created: 2026-08-04 19:31

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "B"

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

#define int long long

const int MAXN = 1e5 + 5;

int a[MAXN], b[MAXN];
vector<int> g[MAXN];
int dp0[MAXN], dp1[MAXN];

void dfs(int u, int p) {
    int s = 0;
    vector<int> d;

    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        s += dp1[v];
        d.pb(dp0[v] - dp1[v]);
    }

    sort(all(d));
    int m = d.size();
    
    vector<int> p(m + 1, 0);
    for
}

void testcase() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}