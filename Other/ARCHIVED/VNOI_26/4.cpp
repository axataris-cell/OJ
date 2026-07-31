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
// Created: 2026-07-24 09:55

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "4"

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

void Kevin() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> color(n + 1, 0);
        vector<int> g[n + 1];
        for (int i = 1; i <= m; i++) {
            int a, b; cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        for (int i = 1; i <= n; i++) cin >> color[i];

    }
}

void Stuart() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> g[n + 1];
        for (int i = 1; i <= m; i++) {
            int a, b; cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        int k; cin >> k;
        vector<int> mes(k + 1, 0);
        for (int i = 1; i <= k; i++) cin >> mes[i];
        
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    if (s == "Kevin") Kevin();
    else Stuart();

    return 0;
}