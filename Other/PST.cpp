#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-18 10:20

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

const int MAXN = 1e5 + 5;

vector<int> a(MAXN, 0);

struct Node {
    int mx;
    Node *l, *r;
    Node (int _v = 0) : mx(_v), l(null), r(null) {}
};

vector<Node*> roots(MAXN, 0);

Node* build(int l, int r) {
    Node* node = new Node();
    if (l == r) {
        node->mx = a[l];
        return node;
    }
    int mid = (l + r) / 2;
    node->l = build(l, mid);
    node->r = build(mid + 1, r);
    node->mx = max(node->l->mx, node->r->mx);

    return node;
}

Node* update(Node* node, int l, int r, int pos, int val) {
    Node* newnode = new Node();
    if (l == r) {
        newnode->mx = val;
        return newnode;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        newnode->l = update(node->l, l, mid, pos, val);
        newnode->r = node->r;
    } else {
        newnode->r = update(node->r, mid + 1, r, pos, val);
        newnode->l = node->l;
    }
    newnode->mx = max(newnode->l->mx, newnode->r->mx);
    return newnode;
}

int query(Node* node, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return node->mx;
    }
    int mid = (l + r) / 2;
    return max(query(node->l, l, mid, ql, qr), query(node->r, mid + 1, r, ql, qr));
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    roots[0] = build(1, n);
    int i = 0;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int pos, val; cin >> pos >> val;
            roots[++i] = update(roots[i - 1], 1, n, pos, val);
        } else {
            int k; cin >> k;
            int l, r; cin >> l >> r;
            cout << query(roots[k], 1, n, l, r);
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