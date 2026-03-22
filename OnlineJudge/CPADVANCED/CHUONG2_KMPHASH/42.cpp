#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-21 22:02

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

string s;
int n;

const int MAXN = 1e6 + 5;
const int BASE = 113;
const int MOD = 1e9 + 7;
vector<int> H(MAXN, 0), P(MAXN, 1);

void build() {
    for (int i = 1; i <= n; i++) {
        H[i] = (H[i - 1] * BASE % MOD + s[i] % MOD) % MOD;
        P[i] = (P[i - 1] * BASE) % MOD;
    }
}

int get(int l, int r) {
    return ((H[r] - H[l - 1] * P[r - l + 1]) % MOD + MOD) % MOD;
}

void testcase() {
    cin >> s;
    n = s.length();
    s = " " + s;
    int cur;

    build();

    vector<int> res;
    for (int len = 1; len <= n; len++) {
        cur = get(1, len);
        bool ok = true;
        for (int i = 1; i <= n; i += len) {
            if (i + len - 1 > n) {
                int diff = n - i + 1;
                if (get(1, diff) != get(i, n)) ok = false;
                break;
            }
            if (get(i, i + len - 1) != cur) {
                ok = false;
                break;
            }
        }
        if (ok) res.push_back(len);
    }
    // cerr << get(1, 1) << ' ' << get(2, 2) << el;

    for (auto x : res) cout << x << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}