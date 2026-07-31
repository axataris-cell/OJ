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
// Created: 2026-07-30 14:08

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "SSANTA"

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

const int MAXN = 1005;

vector<int> adj[MAXN];
int match[MAXN];
bool vis[MAXN];

bool dfs(int u) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = true;

        if (match[v] == 0 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

void testcase() {
    int n; cin >> n;

    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;
        while (k--) {
            int v;
            cin >> v;
            adj[i].pb(v);
        }
    }

    for (int i = 1; i <= n; ++i) {
        fill(vis + 1, vis + n + 1, false);
        dfs(i);
    }

    vector<int> ans(n + 1);
    for (int v = 1; v <= n; ++v)
        if (match[v]) ans[match[v]] = v;

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}