#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-17 07:37

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

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    vector<pii> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b.begin() + 1, b.end(), [](pii x, pii y) {
        if (x.first != y.first) return x.first > y.first;
        else return x.second > y.second;
    });
    int res = 0;
    int cur = INF;
    for (int i = 1; i <= n; i++) {
        if (b[i].second > cur) continue;
        cur = b[i].second;
        ++res;
    }
    cout << res << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}