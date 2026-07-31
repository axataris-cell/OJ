#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll S;
    cin >> n >> S;

    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    int n1 = n / 2;
    int n2 = n - n1;

    vector<pair<ll, int>> right;

    // Sinh tất cả subset của nửa phải
    for (int mask = 0; mask < (1 << n2); mask++) {
        ll sum = 0;
        for (int i = 0; i < n2; i++)
            if (mask >> i & 1)
                sum += a[n1 + i];
        right.push_back({sum, mask});
    }

    sort(right.begin(), right.end());

    // Duyệt nửa trái
    for (int mask = 0; mask < (1 << n1); mask++) {
        ll sum = 0;
        for (int i = 0; i < n1; i++)
            if (mask >> i & 1)
                sum += a[i];

        ll need = S - sum;

        auto it = lower_bound(
            right.begin(), right.end(),
            make_pair(need, -1)
        );

        if (it != right.end() && it->first == need) {
            cout << "YES\n";

            // Truy vết
            vector<int> ans;

            for (int i = 0; i < n1; i++)
                if (mask >> i & 1)
                    ans.push_back(i + 1);

            int rmask = it->second;
            for (int i = 0; i < n2; i++)
                if (rmask >> i & 1)
                    ans.push_back(n1 + i + 1);

            cout << ans.size() << '\n';
            for (int x : ans) cout << x << ' ';
            cout << '\n';
            return 0;
        }
    }

    cout << "NO\n";
}