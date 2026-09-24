#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cost(ll p, ll q, ll x, ll y) {
    return llabs(p - x) + llabs(q - y);
}

ll highest_free_bit(ll p) {
    // tìm bit cao nhất (<= 2^60) sao cho bit đó = 0 trong p
    for (int b = 60; b >= 0; --b) {
        if (((p >> b) & 1) == 0) {
            return (1LL << b);
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y;
    cin >> x >> y;

    const ll INF = (ll)4e18;
    ll best_cost = INF;
    pair<ll, ll> best = {0, 0};

    auto relax = [&](ll p, ll q) {
        if ((p & q) != 0) return;
        ll c = cost(p, q, x, y);
        if (c < best_cost) {
            best_cost = c;
            best = {p, q};
        }
    };

    // 1) Giữ nguyên cả hai
    if ((x & y) == 0) {
        relax(x, y);
    }

    // 2) p = x
    {
        ll p = x;
        ll q = y & ~x;
        relax(p, q);

        if (q == 0) {
            ll bit = highest_free_bit(p);
            if (bit) {
                relax(p, bit);
            }
        }
    }

    // 3) p = y (đối xứng)
    {
        ll p = y;
        ll q = x & ~y;
        relax(p, q);

        if (q == 0) {
            ll bit = highest_free_bit(p);
            if (bit) {
                relax(p, bit);
            }
        }
    }

    cout << best.first << " " << best.second << "\n";
    return 0;
}
