#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    vector<long long> cnt(k, 0);
    cnt[0] = 1;

    long long pref = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pref = (pref + x) % k;
        if (pref < 0) pref += k;

        ans += cnt[pref];
        cnt[pref]++;
    }

    cout << ans;
    return 0;
}
