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
// Created: 2026-07-17 10:55

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "ThamTu"

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

const int MOD = 1e9 + 7;
const int BASE = 113;

void testcase() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    s = " " + s;

    vector<ll> H(n + 1, 0), P(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        H[i] = H[i - 1] * BASE + s[i];
        P[i] = P[i - 1] * BASE;
    }

    auto get = [&](int l, int r) {
        return H[r] - H[l - 1] * P[r - l + 1];
    };

    vector<vector<int>> f(n + 2, vector<int>(n + 2, 0));

    for (int len = 1; len <= n; len++) {
        vector<pair<ll, int>> h;
        h.reserve(n - len + 1);

        for (int i = 1; i <= n - len + 1; i++) {
            h.push_back({get(i, i + len - 1), i});
        }

        sort(all(h));

        vector<int> mark(n + 2, 0);

        for (int i = 0; i < h.size(); i++) {
            if (i == (int)h.size() - 1 || h[i].first != h[i + 1].first) {
                mark[h[i].second] = 1;
            }
        }

        for (int i = n - len + 1; i >= 1; i--) {
            f[i][len] = f[i + 1][len] + mark[i];
        }
    }

    vector<vector<ll>> pref(n + 2, vector<ll>(n + 2, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = f[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    while (m--) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;

        cout << pref[r][q] - pref[l - 1][q] - pref[r][p - 1] + pref[l - 1][p - 1] << el;
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