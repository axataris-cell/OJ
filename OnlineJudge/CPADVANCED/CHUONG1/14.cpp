#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-15 11:16

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

int n;

vector<int> a(MAXN, 0);
vector<int> p(MAXN, 0);
vector<int> bit(MAXN, 0);

void add(int pos, int val) {
    int idx = pos;
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

int sum(int pos) {
    int idx = pos;
    int res = 0;
    while (idx > 0) {
        res += bit[idx];
        idx -= idx & (-idx);
    }
    return res;
}

int kth(int k) {
    int pos = 0;
    for (int pw = 1 << 20; pw; pw >>= 1) {
        if ((pos + pw <= n) && bit[pos + pw] < k) {
            k -= bit[pos + pw];
            pos += pw;
        }
    }
    return pos + 1;
}

void testcase() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++) add(i, 1);

    vector<int> p(n + 1);

    for (int i = n; i >= 1; i--) {
        int k = i - a[i];
        int x = kth(k);
        p[i] = x;
        add(x, -1);
    }

    for (int i = 1; i <= n; i++) cout << p[i] << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}