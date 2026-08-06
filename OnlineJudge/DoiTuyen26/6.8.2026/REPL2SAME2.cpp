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
// Created: 2026-08-06 08:51

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "REPL2SAME2"

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

const int MAXN = 1e6 + 5;

vector<int> g[MAXN];
int p[MAXN]; // pointer

void testcase() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1, 0);
    vector<int> val;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val.pb(a[i]);
    }

    sort(all(val));
    val.erase(unique(all(val)), val.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(all(val), a[i]) - val.begin() + 1;
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        g[a[i]].pb(i);

        int v = a[i];
        int posr = g[v].size() - 1;
        while (p[v] < g[v].size() && i - g[v][p[v]] - (posr - p[v]) > k) ++p[v];

        int l = g[v][p[v]];
        int diff = k - (i - l - (posr - p[v])); 

        res = max(res, i - max(l - diff, 1) + 1);
    }

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