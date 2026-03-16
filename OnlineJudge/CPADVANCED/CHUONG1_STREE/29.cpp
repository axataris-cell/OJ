#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-16 21:35

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

struct Node {
    int mx1, mx2;

    Node() {
        mx1 = 0;
        mx2 = 0;
    }

    Node operator + (const Node &other) const {
        Node res;

        vector<int> temp;
        temp.push_back(this->mx1);
        temp.push_back(this->mx2);
        temp.push_back(other.mx1);
        temp.push_back(other.mx2);

        sort(temp.begin(), temp.end(), greater<int>());

        res.mx1 = temp[0];
        res.mx2 = temp[1];

        return res;
    }
};

vector<int> a(MAXN, 0);
vector<Node> ST(4 * MAXN, Node());

void build(int id, int l, int r) {
    if (l == r) {
        ST[id].mx1 = a[l];
        return;
    }
    int mid = (l + r)/2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

Node query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return Node();
    if (ql <= l && r <= qr) {
        return ST[id];
    }

    int mid = (l + r) / 2;

    return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--) {
        int l, r; cin >> l >> r;
        Node cur = query(1, 1, n, l, r);
        cout << cur.mx2 << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}