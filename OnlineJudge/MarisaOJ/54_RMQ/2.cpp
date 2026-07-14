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
// Created: 2026-07-14 21:58

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "2"

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
const int LOG = 30;
vector<vector<int>> nxt(LOG + 1, vector<int>(MAXN, -1));

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        nxt[0][i] = x;
    }
    for (int l = 1; l <= LOG; l++) {
        for (int i = 1; i <= n; i++) {
            nxt[l][i] = nxt[l - 1][nxt[l - 1][i]];
        }
    }

    while (q--) {
        int u, x; cin >> u >> x;
        for (int i = LOG; i >= 0; i--) {
            if (x >> i & 1) u = nxt[i][u];
        }

        cout << u << el;
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