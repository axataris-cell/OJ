#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll total = 0;
    for (int i = 1; i <= n; i++) total += a[i];

    vector<ll> left(n + 2, 0), right(n + 2, 0);

    ll cur = 0, best = 0;
    for (int i = 1; i <= n; i++) {
        cur = min(a[i], cur + a[i]);
        best = min(best, cur);
        left[i] = best;
    }

    cur = 0; best = 0;
    for (int i = n; i >= 1; i--) {
        cur = min(a[i], cur + a[i]);
        best = min(best, cur);
        right[i] = best;
    }

    ll min1 = left[n];
    ll min2 = min1;

    for (int i = 1; i < n; i++) {
        min2 = min(min2, left[i] + right[i + 1]);
    }

    ll removed = min(0LL, min2);
    cout << max(0LL, total - removed);
}
