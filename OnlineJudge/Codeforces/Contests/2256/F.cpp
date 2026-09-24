#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define null nullptr
#define pb push_back
#define len length
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-08-09 21:38

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "F"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

#define int long long

bool valid(int S, const vector<int>& a) {
    int n = a.size();
    if (S < n) return false;

    int large = max(0LL, S - 30);

    if (large >= n) return true;

    vector<int> rem(a.begin() + large, a.end());

    int mxk = min(S - 1, 29LL);
    for (int k = mxk; k >= 0; --k) {
        if (rem.empty()) break;

        auto max_it = max_element(all(rem));
        int val = *max_it - (1LL << k);

        if (val <= 0) {
            rem.erase(max_it);
        } else {
            *max_it = val;
        }
    }

    return rem.empty();
}

void testcase() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(rall(a));

    for (int S = n; S <= n + 30; ++S) {
        if (valid(S, a)) {
            cout << S << el;
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}