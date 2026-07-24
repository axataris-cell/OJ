#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define null nullptr
#define pb push_back
#define len length
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-07-24 13:56

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "3"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

void testcase() {
    int n, m; cin >> n >> m;
    vector<int> s[n + 1];
    vector<int> res[n + 1];
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        s[x].pb(i);
        res[x].pb(i);
    }
    vector<pii> cur(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        cur[i].fi = s[i].size();
    }
    pqueue<pii> pq;
    pqueue<pii, vector<pii>, greater<pii>> counter;
    for (int i = 1; i <= n; i++) {
        pq.emplace(s[i].size() * 2, i);
        counter.emplace(s[i].size() * 2, i);
    }

    while (pq.size() && counter.size()) {
        while (pq.size() && (cur[pq.top().se].fi * 2 + cur[pq.top().se].se != pq.top().fi || !s[pq.top().se].size())) pq.pop();
        while (counter.size() && (cur[counter.top().se].fi * 2 + cur[counter.top().se].se != counter.top().fi)) counter.pop();
        if (pq.top().fi == counter.top().fi) break;
        auto [val, idx] = pq.top(); pq.pop();
        auto [val2, idx2] = counter.top(); counter.pop();
        int v = s[idx].back(); s[idx].pop_back();
        res[idx].pop_back();
        res[idx2].push_back(v);
        --cur[idx].fi;
        ++cur[idx2].se;
        pq.emplace(cur[idx].fi * 2 + cur[idx].se, idx);
        counter.emplace(cur[idx2].fi * 2 + cur[idx2].se);
    }

    int mx = 0;
    int mn = INF;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, )
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}