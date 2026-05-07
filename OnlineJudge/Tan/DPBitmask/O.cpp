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
// Created: 2026-05-07 15:09

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "O"

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

#define int long long

struct Procedure {
    int w; // thoi gian
    int a, b; // mask
};

void testcase() {
    int n, m; cin >> n >> m;
    string start; cin >> start;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (start[i] == '1') s += (1 << i);
    }

    
    vector<Procedure> pr(m);
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        string y, z; cin >> y >> z;
        int fi = 0, se = 0;
        for (int j = 0; j < n; j++) {
            if (y[j] == '1') fi += (1 << j);
            if (z[j] == '1') se += (1 << j);
        }
        pr[i] = {x, fi, se};
    }

    vector<int> dist(1 << n, INF);
    vector<int> par(1 << n, -1);
    pqueue<pll, vector<pll>, greater<pll>> pq;

    pq.emplace(0, s);
    dist[s] = 0;

    // for (auto [w, a, b] : pr) {
    //     cout << w << ' ' << a << ' ' << b << el;
        
    // }
    // return;

    while (pq.size()) {
        auto [d, mask] = pq.top(); pq.pop();
        if (d > dist[mask]) continue;
        for (const auto &[w, a, b] : pr) {
            int nmask = mask;
            for (int i = 0; i < n; i++) {
                if ((nmask >> i & 1) && (a >> i & 1)) nmask ^= (1 << i);
            }
            nmask |= b;
            if (dist[nmask] > dist[mask] + w) {
                dist[nmask] = dist[mask] + w;
                par[nmask] = mask;
                pq.emplace(dist[nmask], nmask);
            }
        }
    }

    // {
    //     auto [w, a, b] = pr[3];
    //     int test = s;
    //     for (int i = 0; i < n; i++) {
    //         if ((a >> i & 1) && (test >> i & 1)) test ^= (1 << i);
    //     }
    //     test |= b;
    //     cout << test;
    //     return;
    // }

    // vector<int> dpath;
    // int cur = 0;
    // while (par[cur] != -1) {
    //     dpath.pb(cur);
    //     cur = par[cur];
    // }
    // dpath.pb(cur);
    // reverse(all(dpath));

    // for (auto x : dpath) cout << x << ' ';
    // cout << el;

    cout << (dist[0] == INF ? -1 : dist[0]) << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}