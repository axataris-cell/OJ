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
// Created: 2026-06-28 15:08

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "FindCentroid"

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
int n;

int res = 0;

vector<int> g[MAXN];
vector<int> sz(MAXN, 0);
void findC(int u, int p) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        findC(v, u);
        sz[u] += sz[v];
    }
    // find Cen
    int sum = 0;
    for (int v : g[u]) {
        if (v == p) continue;
        if (sz[v] > n / 2) return;
        sum += sz[v];
    }
    if (n - sum - 1 > n / 2) return;
    res = u;
}

void testcase() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    findC(1, 1);

    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}