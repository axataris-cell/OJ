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
// Created: 2026-08-01 14:13

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "GCDPath"

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

int val[MAXN];
vector<int> g[MAXN];
int res[MAXN];

void dfs(int u, int p, int curgcd, const vector<int>& S) {
    int ngcd = __gcd(curgcd, val[u]);
    
    vector<int> nxt;
    nxt.pb(curgcd);

    for (int g : S) {
        nxt.pb(__gcd(g, val[u]));
    }

    sort(all(nxt));
    nxt.erase(unique(all(nxt)), nxt.end());

    res[u] = nxt.back();

    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u, ngcd, nxt);
    }
}

void testcase() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> s = {0};
    dfs(1, 0, 0, s);    
    dfs(1, 1, 0, s);

    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
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