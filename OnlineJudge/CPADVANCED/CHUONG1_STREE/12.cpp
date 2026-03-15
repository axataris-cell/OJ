#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-15 10:47

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

const int MAXN = 2e5 + 5;

vector<ll> a(MAXN, 0);

struct Node {
    ll sum;
    Node *l, *r;
    Node(ll _v = 0) : sum(_v), l(null), r(null) {}
};

Node* build(int l, int r) {
    if (l == r) return new Node(a[l]);

    Node* newnode = new Node();
    int mid = (l + r) / 2;
    newnode->l = build(l, mid);
    newnode->r = build(mid + 1, r);

    newnode->sum = newnode->l->sum + newnode->r->sum;
    
    return newnode;
}

Node* update(Node* node, int l, int r, int pos, int val) {
    if (l == r) return new Node(val);

    Node* newnode = new Node();
    int mid = (l + r) / 2;
    if (pos <= mid) {
        newnode->r = node->r;
        newnode->l = update(node->l, l, mid, pos, val);
    } else {
        newnode->l = node->l;
        newnode->r = update(node->r, mid + 1, r, pos, val);
    }

    newnode->sum = newnode->l->sum + newnode->r->sum;
    return newnode;
}

ll query(Node* node, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return 0;
    if (ql <= l && r <= qr) {
        return node->sum;
    }
    int mid = (l + r) / 2;
    return query(node->l, l, mid, ql, qr) + query(node->r, mid+1, r, ql, qr);
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<Node*> root;
    root.push_back(null);
    root.push_back(build(1, n));

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int k, a, x; cin >> k >> a >> x;
            root[k] = update(root[k], 1, n, a, x);
        } else if (t == 2) {
            int k, a, b; cin >> k >> a >> b;
            cout << query(root[k], 1, n, a, b) << el;
        } else if (t == 3) {
            int k; cin >> k;
            root.push_back(root[k]);
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