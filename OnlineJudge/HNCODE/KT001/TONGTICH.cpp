#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

const int MAXN = 2*1e5 + 5;
const ll MOD = 1e9 + 7;
ll A[MAXN] = {};

ll mulmod(ll a, ll b, ll MOD) {
    ll res = 0;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return res;
}

void testcase() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    
    ll sum = 0, sq = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + A[i]) % MOD;
        sq = (sq + mulmod(A[i], A[i], MOD)) % MOD;
    }
    ll res = (mulmod(sum, sum, MOD) - sq + MOD) % MOD;
    res = mulmod(res, (MOD + 1) / 2, MOD);
    
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll t = 1;
    while (t--) testcase();
    
    return 0;
}
