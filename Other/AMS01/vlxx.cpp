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
// Created: 2026-07-14 08:40

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "vlxx"

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
    if (FILE *f = fopen(FILENAME".inp", "r")) {
        fclose(f);
        freopen(FILENAME".inp", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    }
}

const ll BASE = 311;
const ll MOD = 1e9 + 7;

// vector<ll> H, P;

// void buildHash(string s) {
// 	int n = s.length();
// 	H.assign(n + 1, 0);
// 	P.assign(n + 1, 1);

// 	for (int i = 1; i <= n; i++) {
// 		H[i] = (H[i - 1]  * BASE + s[i - 1]) % MOD; // HASH 0.....i - 1.
// 		P[i] = (P[i - 1] * BASE) % MOD;
// 	}
// }

const int MAXN = 2e5 + 5;
vector<ll> P(MAXN, 1);

ll getHash(int l, int r, vector<ll> &H) {
    if (r < l) return 0;
 	return ((H[r] - H[l - 1] * P[r - l + 1]) % MOD + MOD) % MOD;
}

void testcase() {
    int n, m; cin >> n >> m;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<ll>> H(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            H[i][j] = (H[i][j - 1] * BASE + a[i][j - 1]) % MOD;
        }
    }
    // cout << getHash(2, 3, H[1]); return;
    ll res = 0;
    for (int c = 1; c <= m; c++) { // cho tung chu cai bien mat
        map<pll, int> mp;
        for (int i = 1; i <= n; i++) {
            ll pref = getHash(1, c - 1, H[i]);
            ll suff = getHash(c + 1, m, H[i]);
            if (mp.count({pref, suff})) res += mp[{pref, suff}];
            ++mp[{pref, suff}];
        }
    }

    cout << res << el;
}

/*
1
4 3
abc
adc
xyz
xyy
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    for (int i = 1; i < MAXN; i++) {
        P[i] = (P[i - 1] * BASE) % MOD;
    }

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}