#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve_one(vector<int>& a, int h, int k) {
    int n = a.size();
    int S = 0;
    for (int x : a) S += x;

    if (S == 0) return LLONG_MAX;

    int full = (h - 1) / S;
    int dmg = full * S;
    int time = full * (n + k);

    int need = h - dmg;

    // prefix
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i-1] + a[i];

    // no swap
    int best_pos = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (pref[i] >= need) {
            best_pos = i;
            break;
        }
    }

    // suffix max
    vector<int> suf(n);
    suf[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--)
        suf[i] = max(suf[i+1], a[i]);

    // try swap
    for (int i = 0; i < n-1; i++) {
        int cur = pref[i] - a[i];
        int required = need - cur;
        if (suf[i+1] >= required) {
            best_pos = min(best_pos, (int)i);
        }
    }

    if (best_pos == LLONG_MAX)
        return LLONG_MAX;

    time += best_pos + 1;
    return time;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, h, k;
        cin >> n >> h >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << solve_one(a, h, k) << "\n";
    }
}