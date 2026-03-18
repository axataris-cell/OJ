#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-17 17:30

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
    int sum;
    Node *l, *r;

    Node(int _v = 0) : sum(_v), l(null), r(null) {}
};

Node* build(int l, int r) {
    Node* node = new Node();
    if (l == r) return node;
    int mid = (l + r) / 2;
    node->l = build(l, mid);
    node->r = build(mid + 1, r);
    return node;
}

Node* update(Node* node, int l, int r, int pos) {
    Node* newnode = new Node();
    if (l == r) {
        newnode->sum = node->sum + 1;
        return newnode;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        newnode->l = update(node->l, l, mid, pos);
        newnode->r = node->r;
    } else {
        newnode->l = node->l;
        newnode->r = update(node->r, mid + 1, r, pos);
    }
    newnode->sum = newnode->l->sum + newnode->r->sum;
    return newnode;
}

int kth(Node* leftnode, Node* rightnode, int l, int r, int k) {
    if (l == r) return l;
    int cnt = rightnode->l->sum - leftnode->l->sum;
    int mid = (l + r) / 2;
    if (k <= cnt) return kth(leftnode->l, rightnode->l, l, mid, k);
    return kth(leftnode->r, rightnode->r, mid + 1, r, k - cnt);
}

void testcase() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // compress
    vector<int> b = a;
    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
    int m = b.size() - 1;

    vector<Node*> roots(n + 1);
    roots[0] = build(1, m);
    for (int i = 1; i <= n; i++) {
        roots[i] = update(roots[i - 1], 1, m, a[i]);
    }

    while (q--) {
        int i, j, k; cin >> i >> j >> k;
        if (k > j - i + 1) {
            cout << -1 << el;
            continue;
        }
        int pos = kth(roots[i - 1], roots[j], 1, m, k);
        cout << b[pos] << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}