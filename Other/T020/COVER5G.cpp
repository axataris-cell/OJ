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
// Created: 2026-06-25 14:55

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "COVER5G"

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
    int n, m, k; cin >> n >> m >> k;
    vector<int> X(n + 1, 0), C(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }
    if (k == 1) {
        int l = 1, r = 1e9;
        int res = INF;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool ok = false;
            for (int i = 1; i <= n; i++) {
                bool eh = true;
                for (int j = 1; j <= n; j++) {
                    if (abs(X[i] - X[j]) > mid) {
                        eh = false;
                        break;
                    }
                }
                if (eh) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                res = min(res, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << res;
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