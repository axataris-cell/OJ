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
// Created: 2026-07-01 09:41

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "venue"

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
    if (FILE *f = fopen(FILENAME".inp", "r")) {
        fclose(f);
        freopen(FILENAME".inp", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    }
}

#define int long long

void testcase() {
    int n, m; cin >> n >> m;
    vector<int> pos(2 * n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }
    
    if (n == 1) {
        cout << 0 << ' ' << pos[1];
        return;
    }

    // sub1
    if (n <= 1000 && m <= 1000) {
        int res = LINF;
        int respos = -1;
        for (int i = 1; i <= m; i++) {
            int maxdist = 0;
            for (int j = 1; j <= n; j++) {
                maxdist = max(maxdist, min(llabs(i - pos[j]), m - llabs(i - pos[j])));
            }
            if (res > maxdist) {
                res = maxdist;
                respos = i;
            }
        }

        cout << res << ' ' << respos;
        return;
    }

    sort(pos.begin() + 1, pos.begin() + n + 1);
    for (int i = n + 1; i <= 2 * n; i++) pos[i] = pos[i - n];

    int res = LINF;
    int respos = -1;

    for (int r = n; r < 2 * n; r++) {
        int l = r - n + 1;

        int pl = pos[l];
        int pr = pos[r];

        int nr = (pr - pl + m) % m + 1; // ?

        int a = nr - 1; // kim dong ho

        int dist = (a + 1) / 2;
        if (res > dist) {
            res = dist;
            respos = max(pr - dist, pl + dist);
        }
    }

    cout << res << ' ' << respos;
}

/*
4 18
12 3 9 5
*/

/*
8 13
11 8 3 13 6 10 12 7
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}