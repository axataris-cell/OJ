#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200000 + 5;
ll a[MAXN];
ll n, t;

bool check(ll x) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += x / a[i];
        if (sum >= t) return true;
    }
    return sum >= t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll l = 0, r = 1e18;

    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l;
    return 0;
}
