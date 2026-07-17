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
// Created: 2026-07-17 10:40

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "ThamTu"

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
    int n, m, k; cin >> n >> m >> k;
    vector<int> tu, mau;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        tu.pb(x);
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        mau.pb(x);
    }
    // sort(all(tu));
    // tu.erase(unique(all(tu)), tu.end());
    // sort(all(mau));
    // mau.erase(unique(all(mau)), mau.end());

    vector<pii> phanso;
    map<pii, bool> mp;
    for (auto xxx : tu) {
        for (auto q : mau) {
            int p = xxx;
            int gc = __gcd(p, q);
            p /= gc;
            q /= gc;
            if (!mp[{p, q}]) {
                phanso.push_back({p, q});
                mp[{p, q}] = true;
            }
        }
    }

    sort(all(phanso), [](const pii &x, const pii &y) {
        return 1LL * x.first * y.second < 1LL * y.first * x.second;
    });
    // phanso.erase(unique(all(phanso)), phanso.end());

    cout << phanso[k - 1].fi << ' ' << phanso[k - 1].se;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}