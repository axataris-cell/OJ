#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-17 17:21

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const ll MOD = 1e9 + 7;
const int MAXN = 200005;

ll n, q;

struct Node {
    ll sum;
    ll a, b, c, d; // lazy
} st[4 * MAXN];

ll sum1(ll x) {
    x %= MOD;
    return x * (x + 1) % MOD * ((MOD + 1) / 2) % MOD;
}

ll sum2(ll x) {
    x %= MOD;
    return x * (x + 1) % MOD * (2 * x + 1) % MOD * ((MOD + 1) / 6) % MOD;
}

ll sum3(ll x) {
    ll t = sum1(x);
    return t * t % MOD;
}

ll getsum(ll L, ll R, int type) {
    if (L > R) return 0;
    if (type == 1) return (sum1(R) - sum1(L - 1) + MOD) % MOD;
    if (type == 2) return (sum2(R) - sum2(L - 1) + MOD) % MOD;
    return (sum3(R) - sum3(L - 1) + MOD) % MOD;
}

void apply(int id, int l, int r, ll a, ll b, ll c, ll d) {
    ll S1 = getsum(l, r, 1);
    ll S2 = getsum(l, r, 2);
    ll S3 = getsum(l, r, 3);
    ll len = (r - l + 1) % MOD;

    ll add = (a * S3 + b * S2 + c * S1 + d * len) % MOD;

    st[id].sum = (st[id].sum + add) % MOD;

    st[id].a = (st[id].a + a) % MOD;
    st[id].b = (st[id].b + b) % MOD;
    st[id].c = (st[id].c + c) % MOD;
    st[id].d = (st[id].d + d) % MOD;
}

void push(int id, int l, int r) {
    if (st[id].a == 0 && st[id].b == 0 && st[id].c == 0 && st[id].d == 0) return;
    int mid = (l + r) >> 1;

    apply(id << 1, l, mid, st[id].a, st[id].b, st[id].c, st[id].d);
    apply(id << 1 | 1, mid + 1, r, st[id].a, st[id].b, st[id].c, st[id].d);

    st[id].a = st[id].b = st[id].c = st[id].d = 0;
}

void update(int id, int l, int r, int u, int v, ll a, ll b, ll c, ll d) {
    if (r < u || l > v) return;
    if (u <= l && r <= v) {
        apply(id, l, r, a, b, c, d);
        return;
    }
    push(id, l, r);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, a, b, c, d);
    update(id << 1 | 1, mid + 1, r, u, v, a, b, c, d);
    st[id].sum = (st[id << 1].sum + st[id << 1 | 1].sum) % MOD;
}

ll query(int id, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (u <= l && r <= v) return st[id].sum;
    push(id, l, r);
    int mid = (l + r) >> 1;
    return (query(id << 1, l, mid, u, v) + query(id << 1 | 1, mid + 1, r, u, v)) % MOD;
}

void testcase() {
    cin >> n >> q;

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 0) {
            cout << query(1, 1, n, l, r) << el;
        } else {
            ll sign = (type == 1 ? 1 : MOD - 1);

            ll L = l;

            // f(x) = (x-L+1)(x-L+2)(x-L+3)
            // x^3 + (-3L+6)x^2 + (3L^2 -12L +11)x + (-L^3 +6L^2 -11L +6)

            ll a = sign % MOD;
            ll b = sign * ((-3 * L + 6) % MOD + MOD) % MOD;
            ll c = sign * ((3 * L % MOD * L % MOD - 12 * L + 11) % MOD + MOD) % MOD;
            ll d = sign * ((-L % MOD * L % MOD * L % MOD + 6 * L % MOD * L % MOD - 11 * L + 6) % MOD + MOD) % MOD;

            update(1, 1, n, l, r, a, b, c, d);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); // file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}