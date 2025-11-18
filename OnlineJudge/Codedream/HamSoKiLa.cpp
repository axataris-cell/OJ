#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;

ll mulmod(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            res += a;
            if (res >= mod) res -= mod;
        }
        a <<= 1;
        if (a >= mod) a -= mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x, a, b, c, m;
    cin >> n >> x >> a >> b >> c >> m;

    ll mod = 2 * m;
    vector<ll> cnt(mod, 0);

    ll u = x;

    for (ll i = 0; i < n; i++) {
        cnt[u + m]++;

        ll s1 = mulmod(u, u, mod);
        ll t1 = mulmod(a, s1, mod);
        ll t2 = mulmod(b, u, mod);

        ll v = t1 + t2;
        if (v >= mod) v -= mod;
        v += c % mod;
        if (v >= mod) v -= mod;

        u = v - m;
    }

    ll res = 0;
    ll pos = 1;

    for (ll i = 0; i < mod; i++) {
        if (cnt[i] == 0) continue;

        ll value = i - m;
        ll vmod = (value % MOD + MOD) % MOD;

        ll ccount = cnt[i] % MOD;

        ll term1 = (ccount * (pos % MOD)) % MOD;
        ll term2 = (ccount * ((cnt[i] - 1) % MOD)) % MOD;
        term2 = (term2 * 500000004L) % MOD;

        ll spos = (term1 + term2) % MOD;

        res = (res + vmod * spos) % MOD;

        pos += cnt[i];
    }

    cout << res;
}
	