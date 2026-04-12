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
// Created: 2026-04-10 16:45

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "1"

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

struct Treap {
    struct Node {
        int val;
        int sz; //imp
        int mn;
        int pri;
        Node *l, *r;
        Node(int v) : val(v), mn(v), sz(1), pri(mt()), l(null), r(null) {}
    };

    Node *t; // root

    int getmn(Node *u) {return u ? u->mn : INF;}
    int getsz(Node *u) {return u ? u->sz : 0;}
    int getval(Node *u) {return u ? u->val : 0;}

    void upd(Node *u) {
        if (u) {
            u->sz = getsz(u->l) + getsz(u->r) + 1;
            u->mn = min({getmn(u->l), getmn(u->r), u->val});
        }
    }

    void split(Node *t, Node* &l, Node* &r, int k) {
        if (!t) {
            l = r = null;
            return;
        }

        if (getsz(t->l) >= k) {
            split(t->l, l, t->l, k);
            r = t;
        } else {
            split(t->r, t->r, r, k - getsz(t->l) - 1);
            l = t;
        }

        upd(t);
    }

    Node* merge(Node *l, Node *r) {
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

    int query(int l, int r) {
        Node *a, *b, *c;
        split(t, a, b, l - 1);
        split(b, b, c, r - l + 1);
        int res = getmn(b);
        t = merge(a, merge(b, c));
        
        return res;
    }

    void add(int pos, int val) {
        Node *a, *b;
        split(t, a, b, pos - 1);
        t = merge(merge(a, new Node(val)), b);
    }
};

void testcase() {

    Treap treap;
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        treap.add(i, x);
    }

    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 1) {
            treap.add(u, v);
        } else {
            cout << treap.query(u, v) << el;
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