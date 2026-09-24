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
// Created: 2026-05-11 11:18

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "1579D"

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
    vector<int> a(n + 1, 0);
    pqueue<pii, vector<pii>> pq;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pq.emplace(a[i], i);
    }
    int cnt = 0;
    vector<pii> res;
    while (pq.size()) {
        auto u = pq.top(); pq.pop();

        pii v = {-1, -1};
        if (pq.size()) {
            v = pq.top();
            pq.pop();
        }
        if (v.fi == -1) break;

        if (u.fi < v.fi) swap(u, v);

        if (u.fi == v.fi) {
            for (int i = 1; i <= u.fi; i++) res.pb({u.se, v.se});
            cnt += u.fi;
        } else {
            for (int i = 1; i <= v.fi; i++) res.pb({u.se, v.se});
            cnt += v.fi;
            pq.emplace(u.fi - v.fi, u.se);
        }
    }

    cout << cnt << el;
    for (auto x : res) cout << x.fi << ' ' << x.se << el;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}