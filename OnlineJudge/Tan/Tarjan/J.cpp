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
// Created: 2026-04-16 15:47

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "J"

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
vector<int> tin(MAXN, 0), low(MAXN, 0);
bool del[MAXN];
stack<int> tarjan;

vector<int> scc(MAXN, 0);

int sccCount = 0;
int timeDfs = 0;
void tj(int u) {
    tin[u] = low[u] = ++timeDfs;
    tarjan.push(u);
    for (const int &v : g[u]) {
        if (del[v]) continue;
        if (!tin[v]) {
            tj(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], tin[v]);
    }
    if (low[u] == tin[u]) {
        int v;
        ++sccCount;
        do {
            v = tarjan.top();
            tarjan.pop();
            del[v] = true;
            scc[v] = sccCount;
        } while (u != v);
    }
}

vector<int> dag[MAXN];
vector<int> indeg(MAXN, 0);
vector<int> outdeg(MAXN, 0);

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!tin[i]) tj(i);
    }
    // build DAG
    for (int u = 1; u <= n; u++) {
        for (auto v : g[u]) {
            if (scc[u] != scc[v]) {
                dag[scc[u]].pb(scc[v]);
                ++indeg[scc[v]];
                ++outdeg[scc[u]];
            }
        }
    }
    
    int in0 = 0, out0 = 0;
    for (int u = 1; u <= sccCount; u++) {
        if (indeg[u] == 0) ++in0;
        if (outdeg[u] == 0) ++out0;
    }

    cout << (sccCount == 1 ? 0 : max(in0, out0));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}