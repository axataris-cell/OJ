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
// Created: 2026-07-22 08:25

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "MauPhanBiet"

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

vector<int> color(MAXN, 0);
vector<int> res(MAXN, 0);
vector<int> g[MAXN];
map<int, int> c[MAXN];

void dfs(int u, int p) {
    c[u][color[u]]++;
    int mx = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (c[v].size() > c[u].size()) swap(c[u], c[v]);
        for (auto &[k, v] : c[v]) {
            auto &x = c[u][k];
            x += v;
        }
    }
    for (auto &[k, v] : c[u]) {
        mx = max(mx, v);
    }
    for (auto &[k, v] : c[u]) {
        if (v == mx) {
            res[u] += k;
        }
    }
}

void testcase() {
    int n; cin >> n;   
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 1);
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