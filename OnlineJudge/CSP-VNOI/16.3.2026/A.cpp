#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-16 19:13

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "ATRISET"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

void testcase() {
    int n; cin >> n;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    ll cnt = 0, maxSum = LLONG_MIN;
    bool found = false;

    for (int j = 1; j < n - 1; j++) {
        int l = 0, r = n - 1;
        ll target = 2LL * a[j];

        while (l < j && r > j) {
            ll s = a[l] + a[r];
            if (s < target) l++;
            else if (s > target) r--;
            else {
                ll valL = a[l], valR = a[r];

                if (valL == valR) {
                    ll L = j - (lower_bound(a.begin(), a.begin() + j, valL) - a.begin());
                    ll R = upper_bound(a.begin() + j + 1, a.end(), valR) - (a.begin() + j + 1);
                    cnt += L * R;
                    maxSum = max(maxSum, valL + a[j] + valR);
                    found = true;
                    break;
                }

                ll cL = 0, cR = 0;
                while (l < j && a[l] == valL) cL++, l++;
                while (r > j && a[r] == valR) cR++, r--;

                cnt += cL * cR;
                maxSum = max(maxSum, valL + a[j] + valR);
                found = true;
            }
        }
    }

    if (!found) cout << 0 << el << 0 << el;
    else cout << cnt << el << maxSum << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}