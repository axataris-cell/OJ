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
// Created: 2026-03-22 21:23

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "51"

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

const ll BASE = 311;
const ll MOD = 1000000007;
const int MAXN = 200005;

int n, q;
string s, rs;

ll pw[MAXN];

struct Node {
    ll hash;
    int len;
    Node(ll h = 0, int l = 0) {
        hash = h;
        len = l;
    }
};

Node mergeNode(Node L, Node R) {
    Node res;
    res.len = L.len + R.len;
    res.hash = (L.hash * pw[R.len] % MOD + R.hash) % MOD;
    return res;
}

struct SegTree {
    Node st[4 * MAXN];

    void build(int id, int l, int r, string &a) {
        if (l == r) {
            st[id] = Node(a[l] , 1);
            return;
        }

        int mid = (l + r) >> 1;

        build(id<<1, l, mid, a);
        build(id<<1|1, mid+1, r, a);

        st[id] = mergeNode(st[id<<1], st[id<<1|1]);
    }

    void update(int id, int l, int r, int pos, char val) {
        if (l == r) {
            st[id] = Node(val, 1);
            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid)
            update(id<<1, l, mid, pos, val);
        else
            update(id<<1|1, mid+1, r, pos, val);

        st[id] = mergeNode(st[id<<1], st[id<<1|1]);
    }

    Node get(int id, int l, int r, int u, int v) {
        if (v < l || r < u)
            return Node(0, 0);

        if (u <= l && r <= v)
            return st[id];

        int mid = (l + r) >> 1;

        Node L = get(id<<1, l, mid, u, v); 
        Node R = get(id<<1|1, mid+1, r, u, v);

        return mergeNode(L, R);
    }
};

SegTree st1, st2;

void testcase() {
    cin >> n >> q;
    cin >> s;

    s = " " + s;

    rs = s;
    reverse(rs.begin() + 1, rs.end());

    pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = pw[i-1] * BASE % MOD;

    st1.build(1, 1, n, s);
    st2.build(1, 1, n, rs);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int k;
            char ch;
            cin >> k >> ch;

            st1.update(1, 1, n, k, ch);
            st2.update(1, 1, n, n-k+1, ch);
        }
        else {
            int l, r;
            cin >> l >> r;

            Node h1 = st1.get(1, 1, n, l, r);
            Node h2 = st2.get(1, 1, n, n-r+1, n-l+1);

            if (h1.hash == h2.hash)
                cout << "YES" << el;
            else
                cout << "NO" << el;
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