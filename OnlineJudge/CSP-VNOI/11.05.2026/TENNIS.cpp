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
// Created: 2026-05-11 19:19

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "TENNIS"

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

void testcase() {
    int n; cin >> n;
    vector<int> deg(n + 1, 0);
    pqueue<pii> pq;
    for (int i = 1; i <= n; i++) {
        cin >> deg[i];
        if (deg[i] > 0) pq.emplace(deg[i], i);
    }
    vector<pii> res;
    while (pq.size()) {
        auto u = pq.top(); pq.pop();
        stack<pii> out;

        for (int i = 1; i <= u.fi; i++) {
            if (pq.size()) {
                auto v = pq.top(); pq.pop();
                res.pb({u.se, v.se});
                if (v.fi > 0) out.emplace(v.fi - 1, v.se);
            } else {
                cout << -1 << el;
                return;
            }
        }

        while (out.size()) {
            auto v = out.top(); out.pop();
            pq.emplace(v.fi, v.se);
        }
    }

    for (auto u : res) cout << u.fi << ' ' << u.se << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}