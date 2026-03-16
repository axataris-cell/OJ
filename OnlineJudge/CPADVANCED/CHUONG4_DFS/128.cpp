#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-17 00:00
// Đế chế lọ vương

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 1e5 + 203;

vector<int> g[MAXN];
vector<int> tin(MAXN, 0), tout(MAXN, 0), low(MAXN, 0), par(MAXN, 0);

int ti = 0;
void dfs(int u, int prev) {
    tin[u] = low[u] = ++ti;
    for (int v : g[u]) {
        if (v == prev) continue;
        if (!tin[v]) {
            par[v] = u;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }
    tout[u] = ti;
}

void testcase() {
    int n, s; cin >> n >> s;
    int a, b;
    while (cin >> a >> b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(s, s);
    int best = 0;
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        if (low[i] == s) {
            best = i;
            break;
        }
    }
    if (best == 0) {
        cout << "NO" << el;
        return;
    }
    vector<int> res;
    while (best != s) {
        res.push_back(best);
        best = par[best];
    }
    cout << "YES" << el;
    cout << s << ' ';
    for (auto x : res) cout << x << ' ';
    cout << s << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}