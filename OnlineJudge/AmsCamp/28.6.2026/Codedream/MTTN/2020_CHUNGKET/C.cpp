#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

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

#define int long long

const int MAXN = 1e5 + 5;

struct Node {
    int key;
    int pri;
    int val;
    int mx;
    int sz;
    Node *l, *r;
    Node(int k, int v) : key(k), pri(mt()), val(v), mx(v), sz(1), l(null), r(null) {}
};

Node *tree;

int getmx(Node *t) {
    return t ? t->mx : -LINF;
}

int getsz(Node *t) {
    return t ? t->sz : 0;
}

void upd(Node *t) {
    if (t) {
        t->mx = max({getmx(t->l), getmx(t->r), t->val});
        t->sz = getsz(t->l) + getsz(t->r) + 1;
    }
}

void split(Node *t, Node* &l, Node* &r, int val) {
    if (!t) {
        l = r = null;
        return;
    }
    if (t->key <= val) {
        split(t->r, t->r, r, val);
        l = t;
    } else {
        split(t->l, l, t->l, val);
        r = t;
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

int query(Node *t, int v) {
    int res = -LINF;
    while (t) {
        if (t->key <= v) {
            res = max(res, max(t->val, getmx(t->l)));
            t = t->r;
        } else {
            t = t->l;
        }
    }
    return res;
}

Node* prune(Node* t, int v) {
    if (!t) return null;
    if (t->val <= v) {
        Node* res = prune(t->r, v);
        return res;
    }
    t->l = prune(t->l, v);
    upd(t);
    return t;
}

Node* insert(Node *t, int k, int v) {
    Node *l, *mid, *r;
    split(t, l, r, k - 1);
    split(r, mid, r, k);

    if (mid) {
        mid->val = max(mid->val, v);
        upd(mid);
    } else {
        mid = new Node(k, v);
    }

    r = prune(r, mid->val);

    return merge(merge(l, mid), r);
}

void mergeTree(Node *node, Node* &tree) {
    if (!node) return;

    if (getsz(node) > getsz(tree)) swap(node, tree);

    tree = insert(tree, node->key, node->val);

    mergeTree(node->l, tree);
    mergeTree(node->r, tree);
}

void testcase() {
    int n; cin >> n;
    tree = null;
    tree = insert(tree, 0, 0);

    for (int i = 1; i <= n; i++) {
        int sz; cin >> sz;
        vector<int> coin(sz);
        for (auto &c : coin) cin >> c;

        Node *ntree = null;

        for (int c : coin) {
            int best = query(tree, c);
            if (best == -LINF) continue;
            int nval = best + c;
            ntree = insert(ntree, c, nval);
        }

        mergeTree(ntree, tree);
    }

    cout << getmx(tree) << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1;
    while (t--) testcase();

    return 0;
}