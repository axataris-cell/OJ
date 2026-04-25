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
// Created: 2026-04-16 10:20

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Mono"

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

const int MAXN = 5e5 + 5;

struct Edge {
int v, id;
};

vector<Edge> g[MAXN];
vector<int> tin(MAXN, 0), low(MAXN, 0);
vector<bool> isBridge(MAXN, false);
vector<int> ecc(MAXN, 0);
stack<int> tarjan;

int timeDfs = 0;
int eccCount = 0;

void tj(int u, int preid) {
    tin[u] = low[u] = ++timeDfs;
    tarjan.push(u);
    for (const auto &[v, id] : g[u]) {
        if (id == preid) continue;
        if (!tin[v]) {
            tj(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] == tin[v]) isBridge[id] = true;
        } else low[u] = min(low[u], tin[v]);
    }
    if (tin[u] == low[u]) {
        int v;
        ++eccCount;
        do {
            v = tarjan.top();
            tarjan.pop();
            ecc[v] = eccCount;
        } while (u != v);
    }
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb({b, i});
        g[b].pb({a, i});
    }
    for (int i = 1; i <= n; i++) {
        if (!tin[i]) tj(i, -1);
    }
    for (int i = 1; i <= n; i++) {
        cout << ecc[i] << ' ';
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