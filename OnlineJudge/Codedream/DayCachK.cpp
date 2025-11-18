#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; ++i) cin >> A[i];

    int l = 0;
    int s = -1;
    int p = -1;

    for (int start = 1; start <= k && start <= n; ++start) {
        vector<int> idx;
        for (int x = start; x <= n; x += k) idx.push_back(x);

        int t = idx.size();
        if (t < 2) continue;

        int L = 0;
        for (int R = 1; R < t; ++R) {
            ll x = A[idx[R-1]];
            ll y = A[idx[R]];

            bool ok = false;
            if (x != 0 && y % x == 0) ok = true;
            if (y != 0 && x % y == 0) ok = true;

            if (!ok) {
                L = R;
                continue;
            }

            int ln = R - L + 1;
            if (ln >= 2) {
                int actual_start = idx[L];
                if (ln > l || (ln == l && (s == -1 || actual_start < s))) {
                    l = ln;
                    s = actual_start;
                    p = L;
                }
            }
        }
    }

    if (l < 2) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < l; ++i) {
        if (i) cout << ' ';
        cout << (s + i * k);
    }
    cout << '\n';
    return 0;
}
