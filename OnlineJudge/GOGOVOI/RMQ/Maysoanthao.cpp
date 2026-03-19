#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-19 21:02

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

struct Node {
    char val;
    int pri, sz;
    Node *l, *r;

    Node(char v) {
        sz = 1;
        pri = mt();
        l = null;
        r = null;
        val = v;
    }
};

int getsz(Node *t) {
    return t ? t->sz : 0;
}

Node* clone(Node* t) {
    if (!t) return null;
    Node *n = new Node(*t);
    return n;
}

void upd(Node *t) {
    if (t) {
        t->sz = getsz(t->l) + getsz(t->r) + 1;
    }
}

Node* merge(Node* l, Node* r) {
    if (!l || !r) return l ? l : r;

    if (l->pri > r->pri) {
        Node* nl = clone(l);
        nl->r = merge(nl->r, r);
        upd(nl);
        return nl;
    } else {
        Node* nr = clone(r);
        nr->l = merge(l, nr->l);
        upd(nr);
        return nr;
    }
}

void split(Node* t, Node* &l, Node* &r, int k) {
    if (!t) {
        l = nullptr;
        r = nullptr;
        return;
    }

    t = clone(t);

    if (getsz(t->l) >= k) {
        split(t->l, l, t->l, k);
        r = t;
    } else {
        split(t->r, t->r, r, k - getsz(t->l) - 1);
        l = t;
    }

    upd(t);
}

char kth(Node* t, int k) {
    int l = getsz(t->l);
    if (k < l) return kth(t->l, k);
    if (k == l) return t->val;
    return kth(t->r, k - l - 1);
}

void testcase() {
    int n; cin >> n;

    vector<Node*> ver;

    ver.push_back(null);

    for (int i = 1; i <= n; i++) {
        char t; cin >> t;
        if (t == 'T') {
            char c; cin >> c;
            Node* newnode = new Node(c);
            ver.push_back(merge(ver.back(), newnode));
        } else if (t == 'U') {
            int k; cin >> k;
            ver.push_back(ver[ver.size() - k - 1]);
        } else {
            int x; cin >> x;
            cout << kth(ver.back(), x) << el;
            // ver.push_back(ver.back());
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