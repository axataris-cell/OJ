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
// Created: 2026-05-07 15:58

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "P"

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

vector<int> p3(15, 1);

void changebit3(int &x, const int &idx, const int &val) {
    int old = (x / p3[idx]) % 3;
    x = x - old * p3[idx] + val * p3[idx];
}

int getbit3(const int &x, const int &pos) {
    return (x / p3[pos]) % 3;
}

void testcase() {
    int n, m; cin >> m >> n;
    for (int i = 1; i < 15; i++) p3[i] = p3[i - 1] * 3;
    vector<int> P(m, 0);
    for (int i = 0; i < m; i++) cin >> P[i];
    vector<int> people[m];
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int x;
        while (ss >> x) {
            people[x - 1].pb(i);
        }
    }

    vector<vector<int>> dp(m, vector<int>(p3[n], INF));

    dp[0][0] = 0;
    int _mask = 0;
    for (auto p : people[0]) changebit3(_mask, p, 1);
    if (_mask != 0) dp[0][_mask] = P[0];

    for (int i = 1; i < m; i++) {
        for (int mask = 0; mask < p3[n]; mask++) {
            dp[i][mask] = min(dp[i][mask], dp[i - 1][mask]);
            
            bool ok = true;
            int new_mask = mask;
            for (auto p : people[i]) {
                if (getbit3(mask, p) == 2) {
                    ok = false;
                    break;
                }
                int old = getbit3(new_mask, p);
                changebit3(new_mask, p, old + 1);
            }
            if (!ok) continue;

            dp[i][new_mask] = min(dp[i][new_mask], dp[i - 1][mask] + P[i]);
        }
    }

    cout << (dp[m - 1][p3[n] - 1] == INF ? -1 : dp[m - 1][p3[n] - 1]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}