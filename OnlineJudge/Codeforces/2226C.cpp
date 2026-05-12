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
// Created: 2026-05-12 08:58

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "2226C"

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
    vector<int> mp(1e6 + 5, 0);
    int mxel = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ++mp[a[i]];
        mxel = max(mxel, a[i]);
    }
    sort(a.begin() + 1, a.end());
    int p1 = 0; // pointer in mp - mp[p1]
    int p2 = 1; // pointer in array - a[p2]
    while (p1 <= mxel && p2 <= n) {
        // tang p1 toi cho trong tiep theo
        while (p1 <= mxel && mp[p1]) ++p1;
        if (p1 > mxel) break;

        // tang p2 sao cho a[p2] > p1 (xu ly dong du)
        while (p2 <= n && a[p2] <= p1) ++p2;
        while (p2 <= n && !mp[a[p2]]) ++p2; // neu khong con
        if (p2 > n) break;

        bool fixed = false;
        for (int i = p2; i <= n; i++) {
            if (!mp[a[i]]) continue;
            // if (a[i] == 2) {
            //     if (p1 == 1) break;
            //     --mp[a[i]];
            //     ++mp[p1];
            //     fixed = true;
            //     break;
            // }
            int x = a[i] - p1;
            for (int j = 1; j * j <= x; j++) {
                if (x % j) continue;
                int k = x / j;
                if (a[i] % j == p1 || a[i] % k == p1) {
                    fixed = true;
                    --mp[a[i]];
                    ++mp[p1];
                    break;
                }
            }
            if (fixed) break;
        }
        if (!fixed) break;
    }

    int mex = 0;
    for (int i = 0; i <= 1e6; i++) {
        if (!mp[i]) {
            mex = i;
            break;
        }
    }
    cout << mex << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}