#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;

    ll d = b - a;

    // số bước tối thiểu nếu không có cản trở
    ll base = (d + 1) / 2;

    // đếm số bội của c nằm trong (a, b)
    ll L = (b - 1) / c - a / c;

    ll bad = 0;
    if (L > 0) {
        ll k0 = a / c + 1;                 // bội đầu tiên > a
        ll parity = (k0 * c - a) & 1;      // chẵn / lẻ

        if (c % 2 == 0) {
            // c chẵn: hoặc tất cả xấu hoặc không có
            if (parity == 1) bad = L;
        } else {
            // c lẻ: chẵn lẻ luân phiên
            if (parity == 1)
                bad = (L + 1) / 2;   // ceil(L/2)
            else
                bad = L / 2;         // floor(L/2)
        }
    }

    cout << base + bad;
    return 0;
}
