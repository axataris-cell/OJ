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
// Created: 2026-07-06 09:38

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "RMQSecond"

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

const int MAXN = 3e5 + 5;
const int LOG = 30;

int n, q;

struct Node {
    int mx1;
    int mx2;
};

Node mergeNode(const Node &l, const Node &r) {
    Node res;
    if (l.mx1 > r.mx1) {
        res.mx1 = l.mx1;
        res.mx2 = max({r.mx1, r.mx2, l.mx2});
    } else {
        res.mx1 = r.mx1;
        res.mx2 = max({r.mx2, l.mx1, l.mx2});
    }
    return res;
}

vector<vector<Node>> ST(LOG + 1, vector<Node>(MAXN, {-INF, -INF}));
vector<int> a(MAXN, 0);

void build() {
    for (int i = 1; i <= n; i++) ST[0][i] = {a[i], -INF};
    for (int l = 1; l <= LOG; l++) {
        for (int i = 1; i + (1 << l) - 1 <= n; i++) {
            ST[l][i] = mergeNode(ST[l - 1][i], ST[l - 1][i + (1 << (l - 1))]);
        }
    }
}

Node query(int l, int r) {
    int k = r - l + 1;
    Node res = {-INF, -INF};
    for (int i = 0; k - (1 << i) >= 0; i++) {
        if (k >> i & 1) {
            res = mergeNode(res, ST[i][r - (1 << i) + 1]);
            r -= (1 << i);
        }
    }
    return res;
}

void testcase() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        Node bruh = query(l, r);
        cout << bruh.mx1 + bruh.mx2 << el;    
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