#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-16 20:37

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
const int MOD = 1e9;

struct Node {
    int sum;
    int cnt;

    Node() {
        sum = 0;
        cnt = 0;
    }

    Node operator + (const Node &other) const {
        Node res;
        res.sum = (this->sum + other.sum) % MOD;
        res.cnt = this->cnt + other.cnt;
        return res;
    }
};

vector<Node> ST(4 * MAXN, Node());

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        ST[id].cnt++;
        ST[id].sum = (ST[id].sum + val) % MOD;
        return;
    }
    int mid = (l + r) / 2;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

Node query(int id, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return Node();
    if (ql <= l && r <= qr) {
        return ST[id];
    }

    int mid = (l + r) / 2;
    return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
}

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();

    vector<int> dp(n + 1, 0);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        Node cur = query(1, 1, n, a[i] + 1, n);
        if (cur.cnt) {
            dp[i] = ((cur.sum - cur.cnt * b[a[i]]) % MOD + MOD) % MOD;
            sum = (sum + dp[i]) % MOD;
        }
        update(1, 1, n, a[i], b[a[i]]);
    }

    for (int i = 1; i <= n; i++) cerr << dp[i] << ' ';
    cerr << el;

    cout << sum % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}