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
// Created: 2026-03-22 18:06

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "49"

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

const int MAXN = 1e6 + 5;
const int BASE = 113;
const int MOD = 1e9 + 7;

vector<int> HS(MAXN, 0), HT(MAXN, 0), P(MAXN, 1);

int n, m;
string s, t;

void build() {
    for (int i = 1; i <= n; i++) {
        HS[i] = (HS[i - 1] * BASE % MOD + s[i - 1]) % MOD;
    }
    for (int i = 1; i <= m; i++) {
        HT[i] = (HT[i - 1] * BASE % MOD + t[i - 1]) % MOD;
    }
    for (int i = 1; i < MAXN; i++) {
        P[i] = (P[i - 1] * BASE) % MOD;
    }
}

int getS(int l, int r) {
    return ((HS[r] - HS[l - 1] * P[r - l + 1]) % MOD + MOD) % MOD;
}

int getT(int l, int r) {
    return ((HT[r] - HT[l - 1] * P[r - l + 1]) % MOD + MOD) % MOD;
}

char query(int l1, int r1, int l2, int r2) {

    int size1 = r1 - l1 + 1;
    int size2 = r2 - l2 + 1;

    int l = 1, r = min(size1, size2);

    while (l <= r) {
        int mid = (l + r) / 2;
        if (getS(l1, l1 + mid - 1) == getT(l2, l2 + mid - 1)) l = mid + 1;
        else r = mid - 1;
    }

    int common = r;

    if (common == min(size1, size2)) {
        if (size1 < size2) return '<';
        if (size1 > size2) return '>';
        return '=';
    }

    char c1 = s[l1 + common - 1];
    char c2 = t[l2 + common - 1];

    if (c1 < c2) return '<';
    if (c1 > c2) return '>';
    return '=';
}

void testcase() {
    cin >> n >> m;
    cin >> s >> t;
    n = s.len();
    m = t.len();

    build();

    int q; cin >> q;
    while (q--) {
        int l, r, l1, r1;
        cin >> l >> r >> l1 >> r1;
        cout << query(l, r, l1, r1);
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