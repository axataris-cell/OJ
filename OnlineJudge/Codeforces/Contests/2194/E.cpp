#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll INF = 4e18;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<ll> a(n * m);
    for (int i = 0; i < n * m; ++i) cin >> a[i];

    auto idx = [&](int r, int c) { return r * m + c; };

    vector<ll> f(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) f[idx(i, j)] = a[idx(i, j)];
            else {
                ll res = -INF;
                if (i > 0) res = max(res, f[idx(i - 1, j)]);
                if (j > 0) res = max(res, f[idx(i, j - 1)]);
                f[idx(i, j)] = a[idx(i, j)] + res;
            }
        }
    }

    vector<ll> g(n * m);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i == n - 1 && j == m - 1) g[idx(i, j)] = a[idx(i, j)];
            else {
                ll res = -INF;
                if (i < n - 1) res = max(res, g[idx(i + 1, j)]);
                if (j < m - 1) res = max(res, g[idx(i, j + 1)]);
                g[idx(i, j)] = a[idx(i, j)] + res;
            }
        }
    }

    ll ans = INF;
    for (int d = 0; d <= n + m - 2; ++d) {
        ll m1 = -INF, m2 = -INF;
        int r_start = max(0, d - (m - 1)), r_end = min(n - 1, d);
        for (int i = r_start; i <= r_end; ++i) {
            int j = d - i;
            ll v = f[idx(i, j)] + g[idx(i, j)] - a[idx(i, j)];
            if (v > m1) { m2 = m1; m1 = v; }
            else if (v > m2) { m2 = v; }
        }
        for (int i = r_start; i <= r_end; ++i) {
            int j = d - i;
            ll v = f[idx(i, j)] + g[idx(i, j)] - a[idx(i, j)];
            ll h = (v == m1) ? m2 : m1;
            ans = min(ans, max(h, v - 2 * a[idx(i, j)]));
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}