#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-15 19:11

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

int n, q;

vector<int> a(MAXN, 0);
vector<int> bit(MAXN, 0);

void update(int pos, int val) {
    int idx = pos;
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

void build() {
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) update(i, 1);
    }
}

int kth(int k) {
    int pos = 0;
    for (int i = 20; i >= 0; i--) {
        int pw = 1 << i;
        if (pos + pw <= n && bit[pos + pw] < k) {
            pos += pw;
            k -= bit[pos];
        }
    }
    return pos + 1;
}

void testcase() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; cin >> i;
            if (a[i] == 0) {
                update(i, 1);
                a[i] = 1;
            } else {
                update(i, -1);
                a[i] = 0;
            }
        } else {
            int k; cin >> k;
            cout << kth(k) << el;
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