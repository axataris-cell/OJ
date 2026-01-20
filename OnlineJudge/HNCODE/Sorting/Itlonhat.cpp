#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto x : a) cin >> x;

    sort(a.begin(), a.end());

    long long l = 0, r = n - 1;
    long long ans = 0;

    while (l <= r) {
        if (a[l] + a[r] <= k) {
            l++;
            r--;
        } else {
            r--;
        }
        ans++;
    }

    cout << ans;
    return 0;
}
