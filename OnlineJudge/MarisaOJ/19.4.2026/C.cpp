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
// Created: 2026-04-19 22:19

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "C"

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

ll w[MAXN];
vector<int> g[MAXN];
ll sz[MAXN];
ll sumW[MAXN];
int n;

void dfs1(int u) {
    sz[u] = 1;
    sumW[u] = w[u];
    for (int v : g[u]) {
        dfs1(v);
        sz[u] += sz[v];
        sumW[u] += sumW[v];
    }
}

ll timer = 0;
ll ans = 0;

void dfs2(int u) {
    timer++;
    ans += timer * w[u];

    sort(all(g[u]), [](int a, int b) {
        return sumW[a] * sz[b] < sumW[b] * sz[a];
    });

    for (int v : g[u]) {
        dfs2(v);
    }
}

void testcase() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        g[p].push_back(i);
    }

    dfs1(1);
    dfs2(1);

    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}