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
// Created: 2026-07-06 10:10

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Ant"

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

const int MAXN = 2e5 + 5;
const int LOG = 30;

int n, q;

struct Node {
    int mn, cnt;
    int gcd;
    Node(int _mn = LINF, int _cnt = 0, int ngcd = 0) : mn(_mn), cnt(_cnt), gcd(ngcd) {}
};

Node mergeNode(const Node &l, const Node &r) {
    Node res;
    res.gcd = __gcd(l.gcd, r.gcd);
    if (l.mn < r.mn) {
        res.mn = l.mn;
        res.cnt = l.cnt;
    } else if (l.mn > r.mn) {
        res.mn = r.mn;
        res.cnt = r.cnt;
    } else {
        res.mn = l.mn;
        res.cnt = l.cnt + r.cnt;
    }
    return res;
}

vector<vector<Node>> ST(LOG + 1, vector<Node>(MAXN, Node()));
vector<int> a(MAXN, 0);

void build() {
    for (int i = 1; i <= n; i++) ST[0][i] = {a[i], 1, a[i]};
    for (int l = 1; l <= LOG; l++) {
        for (int i = 1; i + (1 << l) - 1 <= n; i++) {
            ST[l][i] = mergeNode(ST[l - 1][i], ST[l - 1][i + (1 << (l - 1))]);
        }
    }
}

Node query(int l, int r) {
    int k = r - l + 1;
    Node res = Node();
    for (int i = 0; k - (1 << i) >= 0; i++) {
        if (k >> i & 1) {
            res = mergeNode(res, ST[i][r - (1 << i) + 1]);
            r -= 1 << i;
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
        Node res = query(l, r);
        if (res.gcd != res.mn) {
            cout << (r - l + 1) << el;
        } else {
            cout << (r - l + 1) - res.cnt << el;
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