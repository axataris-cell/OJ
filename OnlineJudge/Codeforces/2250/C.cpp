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
// Created: 2026-08-05 20:41

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

void testcase() {
    int n; cin >> n;
    vector<int> l(n + 1, 0), r(n + 1, 0), u(n + 1, 0), v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> u[i] >> v[i];
    }

    deque<int> res;
    vector<bool> del(n + 1, false);

    int off = 0;

    for (int i = 1; i <= n; i++) {
        if (l[i] <= i - off && i - off <= r[i]) {
            del[i] = true;
            ++off;
            continue;
        }
        res.push_back(i);
    }

    // vector<int> f(n + 2, 0);
    // for (int i = n; i >= 1; i--) {
    //     f[i] = f[i + 1] + del[i];
    // }

    // int ans = 0;

    // while (res.size()) {
    //     auto i = res.front(); res.pop_front();
    //     if (u[i] <= f[i] && f[i] <= v[i]) {
    //         ++ans;
    //     }
    // }

    cout << res.size() << el;

    // deque<int> res;
    // vector<bool> del(n + 1, false);
    // int offset = 0;
    // for (int i = 1; i <= n; i++) {
    //     int curpos = i - offset;
    //     while (res.size() && l[i] <= curpos && curpos <= r[i]) {
    //         del[res.back()] = true;
    //         res.pop_back();
    //         --curpos;
    //         ++offset;
    //     }
    //     if (l[i] <= curpos && curpos <= r[i]) {
    //         ++offset;
    //         del[i] = true;
    //         continue;
    //     }
    //     res.pb(i);
    // }
    // int curcnt = 0;

    // vector<int> f(n + 5, 0);
    // for (int i = n; i >= 1; i--) {
    //     f[i] = f[i + 1] + del[i];
    // }
    // int ans = 0;
    // while (res.size()) {
    //     int i = res.front(); res.pop_front();
    //     ++ans;
    //     int cntdel = f[i];
    //     while (res.size() && u[i] <= n - i + 1 - cntdel && n - i + 1 - cntdel <= v[i]) {
    //         res.pop_front();
    //         ++cntdel;
    //     }
    // }

    // cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}