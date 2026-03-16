#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-16 18:14

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

#define int long long

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n;

struct Node {
    int mx, index;

    Node() {
        mx = 0;
        index = 0;
    }

    Node operator + (const Node &other) const {
        Node res;
        if (this->mx > other.mx) {
            res.mx = this->mx;
            res.index = this->index;
        } else {
            res = other;
        }

        return res;
    }
};

vector<Node> ST(4 * MAXN);

void update(int id, int l, int r, int pos, int val, int index) {
    if (pos < l || pos > r) return;
    if (l == r) {
        if (ST[id].mx < val) {
            ST[id].mx = val;
            ST[id].index = index;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(id << 1, l, mid, pos, val, index);
    update(id << 1 | 1, mid + 1, r, pos, val, index);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

Node query(int id, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return Node();
    if (ql <= l && r <= qr) return ST[id];
    int mid = (l + r) / 2;
    return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
}

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // nén
    vector<int> b = a;
    sort(b.begin() + 1, b.begin() + n + 1);
    b.erase(unique(b.begin() + 1, b.begin() + n + 1), b.end());
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();

    pll best = {-LINF, 0};
    vector<int> dp(n + 1, 0);
    vector<int> par(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        Node j = query(1, 1, n, 1, a[i] - 1);
        dp[i] = j.mx + 1;
        par[i] = j.index;
        if (best.first < dp[i]) {
            best = {dp[i], i};
        }
        update(1, 1, n, a[i], dp[i], i);
    }

    int cur = best.second;
    vector<int> path;
    while (cur != 0) {
        path.push_back(cur);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());

    cout << path.size() << el;
    for (auto x : path) cout << x << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}