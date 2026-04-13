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
// Created: 2026-04-13 20:23

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "BOCSOI"

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

void testcase() {
    int n;
    ll x, y, z;
    cin >> n >> x >> y >> z;

    vector<int> A, B;
    for (int i = 1; i <= n; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        while (ai--) A.push_back(i);
        while (bi--) B.push_back(i);
    }

    int szA = A.size();
    int szB = B.size();

    vector<ll> dp(szB + 1, 0);
    vector<ll> pre_dp(szB + 1, 0);

    for (int j = 0; j <= szB; ++j) {
        pre_dp[j] = j * x;
    }

    for (int i = 1; i <= szA; ++i) {
        dp[0] = i * y;
        for (int j = 1; j <= szB; ++j) {
            ll cost_delete = pre_dp[j] + y;
            ll cost_insert = dp[j - 1] + x;
            ll cost_move = pre_dp[j - 1] + z * abs(A[i - 1] - B[j - 1]);

            dp[j] = min({cost_delete, cost_insert, cost_move});
        }
        pre_dp = dp;
    }

    cout << pre_dp[szB] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}