#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long mx = a[0];
        long long ans = LLONG_MAX;
        bool hasInv = false;

        for (int i = 1; i < n; i++) {
            if (a[i] < mx) {
                hasInv = true;
                ans = min(ans, mx - a[i]);
            }
            mx = max(mx, a[i]);
        }

        if (!hasInv) {
            cout << 1000000000LL << '\n';
        } else {
            cout << ans << '\n';
        }
    }
}
