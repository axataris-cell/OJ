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
// Created: 2026-03-25 15:31

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "C"

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
    ll n, q;
    cin >> n >> q;

    map<ll, ll> mp;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mp[x]++;
        sum += x;
    }

    cout << sum << el;

    while (q--) {
        ll l, r, x;
        cin >> l >> r >> x;

        auto it = mp.lower_bound(l);

        ll cnt = 0;
        ll rmv = 0;

        vector<ll> era;

        while (it != mp.end() && it->first <= r) {
            cnt += it->second;
            rmv += it->first * it->second;
            era.push_back(it->first);
            it++;
        }

        for (auto v : era) mp.erase(v);

        if (cnt > 0) mp[x] += cnt;

        sum = sum - rmv + cnt * x;

        cout << sum << el;
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