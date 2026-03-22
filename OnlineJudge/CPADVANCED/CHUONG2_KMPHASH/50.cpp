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
// Created: 2026-03-22 20:02

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "50"

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

const int MAXN = 1e5 + 5;
const int BASE = 113;
const int MOD = 1e9 + 7;
int n;
vector<int> H(MAXN, 0), P(MAXN, 1);
vector<int> ST(4 * MAXN, 0);

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = H[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void updateST(int id, int l, int r, int ql, int qr) {

}

int queryST(int id, int l, int r, int ql, int qr) {

}

bool check(int l1, int l2, int k) {

}

void update(int pos) {
    
}

void testcase() {
    string s; cin >> s;
    n = s.len();

    for (int i = 1; i <= n; i++) {
        H[i] = (H[i - 1] * BASE % MOD + s[i - 1]) % MOD;
        P[i] = (P[i - 1] * BASE) % MOD;
    }
    build(1, 1, n);
    int q; cin >> q;
    while (q--) {
        char op;
        cin >> op;
        if (op == '?') {
            int l1, l2, k; cin >> l1 >> l2 >> k;
            if (check(l1, l2, k)) {
                cout << "YES" << el;
            } else cout << "NO" << el;
        } else {
            int pos; cin >> pos;
            update(pos);
        }
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