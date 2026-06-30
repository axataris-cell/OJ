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
// Created: 2026-06-28 15:14

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Commander"

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
int n;

vector<int> g[MAXN];
int sz[MAXN];
bool removed[MAXN];
char ans[MAXN];

int get_sz(int u, int p) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v != p && !removed[v]) {
            sz[u] += get_sz(v, u);
        }
    }
    return sz[u];
}

int get_centroid(int u, int p, int tree_sz) {
    for (int v : g[u]) {
        if (v != p && !removed[v] && sz[v] * 2 > tree_sz) {
            return get_centroid(v, u, tree_sz);
        }
    }
    return u;
}

void decompose(int u, char rank_char) {
    int tree_sz = get_sz(u, 0);
    int c = get_centroid(u, 0, tree_sz);

    if (rank_char > 'Z') {
        cout << "Impossible!" << el;
        exit(0);
    }

    ans[c] = rank_char;
    removed[c] = true;

    for (int v : g[c]) {
        if (!removed[v]) {
            decompose(v, rank_char + 1);
        }
    }
}

void testcase() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    decompose(1, 'A');

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1;
    while (t--) testcase();

    return 0;
}