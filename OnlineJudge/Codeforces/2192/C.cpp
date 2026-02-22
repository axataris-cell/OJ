#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

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
    ll n, h, k;
    cin >> n >> h >> k;

    vector<ll> a(n);
    ll S = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        S += a[i];
    }

    vector<ll> pref(n + 1, 0);
    vector<ll> pm(n + 1, LLONG_MAX);
    vector<ll> sm(n + 1, LLONG_MIN);

    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
        pm[i + 1] = min(pm[i], a[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
        sm[i] = max(sm[i + 1], a[i]);
    }

    auto getmax = [&](int m) {
        if (m == 0) return 0LL;
        if (m == n) return S;
        return max(pref[m], pref[m] - pm[m] + sm[m]);
    };

    ll res = LLONG_MAX;

    for (int m = 1; m <= n; ++m) {
        ll Pm = getmax(m);

        ll cur;
        if (Pm >= h) {
            cur = m;
        } else {
            ll extra = (h - Pm + S - 1) / S;
            cur = m + extra * n + extra * k;
        }

        res = min(res, cur);
    }

    cout << res << el;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    file();

    ll t; 
    cin >> t;
    while (t--) 
        testcase();

    return 0;
}