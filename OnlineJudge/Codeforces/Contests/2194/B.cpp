#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long S = 0;
        for (int i = 0; i < n; i++) {
            S += a[i] / x;
        }

        long long best = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            long long k = a[i] / x;
            long long gain = a[i] - k * y;
            best = max(best, gain);
        }

        cout << S * y + best << "\n";
    }
    return 0;
}
