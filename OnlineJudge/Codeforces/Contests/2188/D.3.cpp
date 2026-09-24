#include <iostream>

using namespace std;

/**
 * Giai quyet tung test case
 */
void solve() {
    long long x, y;
    if (!(cin >> x >> y)) return;

    long long p = 0, q = 0;
    long long p1 = 0, q1 = 0;

    // Duyet qua 31 bit (vi x, y < 2^30)
    for (int i = 0; i <= 30; ++i) {
        int bit_x = (x >> i) & 1;
        int bit_y = (y >> i) & 1;

        if (bit_x == 1 && bit_y == 1) {
            // Truong hop xung dot: p_i & q_i phai bang 0
            // Ta chon p_i = 1 va q_i = 0 (hoac nguoc lai)
            p |= (1LL << i);
            q |= (0LL << i);
            
            p1 |= (0LL << i);
            q1 |= (1LL << i);
        } else {
            // Truong hop khong xung dot: giu nguyen bit cua x va y
            if (bit_x == 1) p |= (1LL << i);
            if (bit_y == 1) q |= (1LL << i);
            
            if (bit_x == 1) q1 |= (1LL << i);
            if (bit_y == 1) p1 |= (1LL << i);
        }
    }

    cout << 1 << ": "<< p << " " << q << endl;
    cout << "2: " << p1 << ' ' << q1 << endl;
}

int main() {
    // Toi uu toc do nhap xuat
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}