#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 1000;

ll powerMod(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll fact[MAXN + 1], invFact[MAXN + 1];

ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

void testcase() {
	ll n, k; cin >> n >> k;
	cout << C(n, k) << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();
	
	fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i % MOD;

    invFact[MAXN] = powerMod(fact[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    
	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
