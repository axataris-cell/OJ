#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5 + 5;
ll n, m;
ll a[MAXN];

bool check(ll x) {
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        tot += x / a[i];
        if (tot >= m) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll l = 0;
    ll r = *min_element(a, a + n) * m;

    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l;
    return 0;
}
