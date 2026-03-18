#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-18 18:08

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int val, mx, sz, pri;
    Node *l, *r;

    Node(int v) {
        val = mx = v;
        sz = 1;
        pri = rng();
        l = r = nullptr;
    }
};

int getSz(Node* t) { return t ? t->sz : 0; }
int getMx(Node* t) { return t ? t->mx : INT_MIN; }

void pull(Node* t) {
    if (!t) return;
    t->sz = 1 + getSz(t->l) + getSz(t->r);
    t->mx = max({t->val, getMx(t->l), getMx(t->r)});
}

void split(Node* t, int k, Node*& l, Node*& r) {
    if (!t) {
        l = r = nullptr;
        return;
    }

    if (getSz(t->l) >= k) {
        split(t->l, k, l, t->l);
        r = t;
    } else {
        split(t->r, k - getSz(t->l) - 1, t->r, r);
        l = t;
    }
    pull(t);
}

Node* merge(Node* l, Node* r) {
    if (!l || !r) return l ? l : r;

    if (l->pri > r->pri) {
        l->r = merge(l->r, r);
        pull(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        pull(r);
        return r;
    }
}

Node* insert(Node* root, int pos, int val) {
    Node *L, *R;
    split(root, pos - 1, L, R);
    return merge(merge(L, new Node(val)), R);
}

int query(Node*& root, int l, int r) {
    Node *A, *B, *C;

    split(root, r, A, C);
    split(A, l - 1, A, B);

    int res = getMx(B);

    root = merge(merge(A, B), C);

    return res;
}

void testcase() {
    int n, q;
    cin >> n >> q;

    Node* root = nullptr;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        root = merge(root, new Node(x));
    }

    while (q--) {
        int t; cin >> t;

        if (t == 1) {
            int i, x;
            cin >> i >> x;
            root = insert(root, i, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(root, l, r) << el;
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