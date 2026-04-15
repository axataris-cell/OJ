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
// Created: 2026-04-15 20:01

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "A"

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

int componentCount = 0;

vector<int> g[MAXN];
vector<int> low(MAXN, 0);
vector<int> tin(MAXN, 0);
vector<bool> del(MAXN, 0);
stack<int> st;

int timeDfs = 0;

void dfs(int u) {
    tin[u] = low[u] = ++timeDfs;
    st.push(u);
    for (int v : g[u]) {
        if (del[v]) continue;
        if (!tin[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], tin[v]);
    }
    if (tin[u] == low[u]) {
        ++componentCount;
        int v;
        do {
            v = st.top();
            st.pop();
            del[v] = true;
        } while (u != v);
    }
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!tin[i]) dfs(i);
    }

    cout << componentCount;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}