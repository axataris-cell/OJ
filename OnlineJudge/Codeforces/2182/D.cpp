#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n + 1);
        for (int i = 0; i <= n; i++) cin >> a[i];

        long long a0 = a[0];
        vector<long long> b(a.begin() + 1, a.end());
        sort(b.begin(), b.end());

        multiset<long long> ms(b.begin(), b.end());

        long long ans = 1;

        for (int k = 1; k <= n; k++) {
            long long need = max(0LL, (long long)k - a0);

            auto it = ms.lower_bound(need);
            if (it == ms.end()) {
                ans = 0;
                break;
            }

            long long choices = distance(it, ms.end());
            ans = ans * choices % MOD;

            ms.erase(it);
        }

        cout << ans << '\n';
    }

    return 0;
}
