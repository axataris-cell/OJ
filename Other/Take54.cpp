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
// Created: 2026-04-10 19:47

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Take54"

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

const int MAXN = 2e5 + 5;

vector<int> a(MAXN, 0);

struct Node {
    int val;
    int sum;
    int pri;
    int sz;
    Node *l, *r;
    Node(int v) : sum(v), val(v), pri(mt()), sz(1), l(null), r(null) {}
};

Node *t;

inline int getsz(Node *t) {return t ? t->sz : 0;}
inline int getsum(Node *t) {return t ? t->sum : 0;}
inline int getval(Node *t) {return t ? t->val : 0;}

void upd(Node *t) {
    if (t) {
        t->sz = getsz(t->l) + getsz(t->r) + 1;
        t->sum = getsum(t->l) + getsum(t->r) + t->val;
    }
}

void split_sz(Node *t, Node* &l, Node* &r, int k) {
    if (!t) {
        l = r = null;
        return;
    }

    if (getsz(t->l) >= k) {
        split_sz(t->l, l, t->l, k);
        r = t;
    } else {
        split_sz(t->r, t->r, r, k - getsz(t->l) - 1);
        l = t;
    }

    upd(t);
}

void split_val(Node *t, Node* &l, Node* &r, int val) {
    if (!t) {
        l = r = null;
        return;
    }

    if (t->val <= val) {
        split_val(t->r, t->r, r, val);
        l = t;
    } else {
        split_val(t->l, l, t->l, val);
        r = t;
    }

    upd(t);
}

Node* merge(Node *l, Node *r) { // dam bao max_l < max_r nhe ae
    if (!l || !r) return l ? l : r;

    if (l->pri > r->pri) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}

void update(int pos, int val) {
    int old = a[pos];
    a[pos] = val;
    Node *x, *y, *z;
    split_val(t, x, y, old - 1);
    split_val(y, y, z, old);
    Node *tmp, *rest;
    split_sz(y, tmp, rest, 1);
    t = merge(x, merge(rest, z));
    split_val(t, x, y, val - 1);
    t = merge(merge(x, new Node(val)), y);
}

int query(int k) {
    Node *a, *b;
    split_sz(t, a, b, k);
    int res = getsum(a);
    t = merge(a, b);
    return res;
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin() + 1, b.begin() + n + 1);
    for (int i = 1; i <= n; i++) {
        t = merge(t, new Node(b[i]));
    }

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v;
            update(u, v);
        } else {
            int k; cin >> k;
            cout << query(k) << el;
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