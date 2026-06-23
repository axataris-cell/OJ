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
// Created: 2026-06-22 15:36

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "E"

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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];u   
    }

    vector<int> ppos(n + 1), npos(n + 1);
    vector<int> last(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        ppos[i] = last[a[i]];
        last[a[i]] = i;
    }

    fill(all(last), n + 1);
    for (int i = n; i >= 1; --i) {
        npos[i] = last[a[i]];
        last[a[i]] = i;
    }

    function<bool(int, int)> check = [&](int l, int r) -> bool {
        if (l >= r) return true;

        int step = 0;
        while (l + step <= r - step) {
            int i1 = l + step;
            if (ppos[i1] < l && npos[i1] > r) {
                return check(l, i1 - 1) && check(i1 + 1, r);
            }

            int i2 = r - step;
            if (ppos[i2] < l && npos[i2] > r) {
                return check(l, i2 - 1) && check(i2 + 1, r);
            }

            step++;
        }

        return false;
    };

    cout << (check(1, n) ? "YES" : "NO") << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t; cin >> t;
    while (t--) testcase();

    return 0;
}