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

// Author: Fua

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

#define int long long

void testcase() {
    int n, q; cin >> n >> q;
    vector<pii> a(n);
    for (auto &x : a) cin >> x.se >> x.fi;
    sort(rall(a));

    vector<int> mxpref(n + 1);
    multiset<int> s;
    int ptr = 0;
    ll mx = 0, cur = 0;
    for (int k = n; k >= 0; k--) {
        while (ptr < n && a[ptr].fi >= k) {
            cur += a[ptr].se;
            s.insert(a[ptr].se);
            ++ptr;
        }
        while (s.size() > k + 1) {
            cur -= *s.begin();
            s.erase(s.begin());
        }
        mx = max(mx, cur);
        mxpref[k] = (s.size() <= k) ? cur : cur - *s.begin();
    }
    for (int k = 1; k <= n; k++) mxpref[k] = max(mxpref[k], mxpref[k - 1]);

    while (q--) {
        int x, y; cin >> x >> y;
        cout << max(mx, (mxpref[y] + x) * 1LL) << ' ';
    }
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}