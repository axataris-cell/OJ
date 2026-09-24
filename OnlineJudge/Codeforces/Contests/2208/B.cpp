#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-14 21:41

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
    int n, k, p, m; cin >> n >> k >> p >> m;
    vector<int> a(n + 1);
    pqueue<pii, vector<pii>, greater<pii>> pq; // value - inddex
    queue<pii> q; // v - i
    int res = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i <= k) {
            if (i != p) pq.push({a[i], i});
        } else {
            q.push({a[i], i});
        }
    }
    if (a[p] > m) {
        cout << 0 << el;
        return;
    }
    if (k >= n) {
        cout << m / a[p] << el;
        return;
    }
    if (p <= k) {
        ++res;
        cur = a[p];
        q.push({a[p], p});
        pq.push(q.front());
        q.pop();
    }
    while (cur <= m) {
        pii x = pq.top();
        pq.pop();
        if (cur + x.first > m) break;
        cur += x.first;
        q.push(x);
        if (q.front().second == p) {
            if (cur + q.front().first > m) break;
            cur += q.front().first;
            ++res;
            q.push(q.front());
            q.pop();
            pq.push(q.front());
            q.pop();
        } else {
            pq.push(q.front());
            q.pop();
        }
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