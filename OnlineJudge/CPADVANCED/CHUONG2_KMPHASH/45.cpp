#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define len length
#define pb push_back
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-22 11:05

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

#define int long long

const int MAXN = 1e5 + 5;
const int BASE = 5123;
const int MOD = 1e9 + 9;

void testcase() {
    int k; cin >> k;
    string s; cin >> s;
    string a, b; cin >> a >> b;
    int n = s.len();
    int m = a.len();
    int l = b.len();
    vector<int> H(MAXN + 1, 0), P(MAXN + 1, 1);
    for (int i = 1; i <= n; i++) {
        H[i] = (H[i - 1] * BASE % MOD + s[i - 1]) % MOD;
        P[i] = (P[i - 1] * BASE) % MOD;
    }

    auto get = [&](int l, int r) {
        return ((H[r] - H[l - 1] * P[r - l + 1]) % MOD + MOD) % MOD;
    };

    int hash1 = 0, hash2 = 0;
    for (int i = 1; i <= m; i++) {
        hash1 = ((hash1 * BASE % MOD + a[i - 1]) % MOD + MOD) % MOD;
    }
    for (int i = 1; i <= l; i++) {
        hash2 = ((hash2 * BASE % MOD + b[i - 1]) % MOD + MOD) % MOD;
    }

    vector<int> posa, posb;
    for (int i = 1; i <= n - m + 1; i++) {
        if (get(i, i + m - 1) == hash1) {
            posa.pb(i);
        }
    }
    for (int i = 1; i <= n - l + 1; i++) {
        if (get(i, i + l - 1) == hash2) {
            posb.pb(i);
        }
    }

    // for (auto x : posa) cout << x << ' ';
    // cout << el;
    // for (auto x : posb) cout << x << ' ';
    // cout << el;
    // for (int i = 1; i <= 9; i++) cout << H[i] << ' ';
    // cout << el;

    for (auto x : posa) {
        auto it = lower_bound(posb.begin(), posb.end(), x);
        while (it != posb.end() && *it + l - 1 < x + m - 1) {
            ++it;
        }
        if (it == posb.end()) {
            break;
        }
        int val = *it;
        if (val <= x + m - 1) {
            cout << "YES" << el;
            return;
        } else {
            if (val - (x + m) <= k) {
                cout << "YES" << el;
                return;
            }
        }
    }
    cout << "NO" << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}