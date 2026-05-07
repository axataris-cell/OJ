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

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "L"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

ll dp[2][3125];
int p5[6];

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

void testcase() {
    int n;
    cin >> n;

    p5[0] = 1;

    for (int i = 1; i <= 5; i++) {
        p5[i] = p5[i - 1] * 5;
    }

    dp[0][0] = 1;

    int cur = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < 5; c++) {
            int nxt = 1 - cur;

            for (int m = 0; m < 3125; m++) {
                dp[nxt][m] = 0;
            }

            for (int m = 0; m < 3125; m++) {
                if (!dp[cur][m]) continue;

                int up = (m / p5[c]) % 5;
                int left = (c == 0 ? -1 : (m / p5[c - 1]) % 5);

                for (int v = 0; v < 5; v++) {
                    if (r > 0 && v == up) continue;
                    if (c > 0 && v == left) continue;

                    int nm = m - up * p5[c] + v * p5[c];

                    dp[nxt][nm] += dp[cur][m];
                    dp[nxt][nm] %= MOD;
                }
            }

            cur = nxt;
        }
    }

    ll ans = 0;

    for (int m = 0; m < 3125; m++) {
        ans += dp[cur][m];
        ans %= MOD;
    }

    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}