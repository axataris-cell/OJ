#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-18 22:18

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

// Bài 38 CP Advanced

struct Node {
    int val, sz, mx;
    int pri;
    Node *l, *r;
    Node(int v) {
        val = v;
        sz = 1;
        mx = v;
        pri = mt();
        l = null;
        r = null;
    }
};

Node* t;

inline int getsz(Node *t) {return t ? t->sz : 0;}
inline int getmx(Node *t) {return t ? t->mx : -INF;}

void upd(Node* &t) {
    if (t) {
        t->sz = getsz(t->l) + getsz(t->r) + 1;
        t->mx = max({getmx(t->l), getmx(t->r), t->val});
    }
}

void split(Node* t, Node* &l, Node* &r, int k) {
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

Node* merge(Node* l, Node* r) {
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

int get(int l, int r) {
    Node *a, *b, *c;
    split(t, a, b, l - 1);
    split(b, b, c, r - (l - 1));
    int res = getmx(b);
    t = merge(a, merge(b, c));
    return res;
}

void put(int pos, int val) {
    Node *a, *b;
    split(t, a, b, pos - 1);
    t = merge(merge(a, new Node(val)), b);
}

void testcase() {
    int n; cin >> n;
    int q; cin >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        t = merge(t, new Node(x));
    }

    while (q--) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            put(a, b);
        } else {
            cout << get(a, b) << el;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}