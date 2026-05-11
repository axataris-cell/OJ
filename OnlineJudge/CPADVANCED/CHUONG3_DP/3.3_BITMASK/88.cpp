#include <bits/stdc++.h>
using namespace std;

// Sử dụng long long cho tất cả các giá trị số và bit
typedef long long ll;

void solve() {
    int Q;
    if (!(cin >> Q)) return;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            ll x; cin >> x;
            cout << __builtin_popcountll(x) << "\n";
        } 
        else if (type == 2) {
            ll x; int i; cin >> x >> i;
            // Trích xuất bit thứ i
            cout << ((x >> i) & 1LL) << "\n";
        } 
        else if (type == 3) {
            ll x; int i; cin >> x >> i;
            // Bật bit thứ i: dùng phép OR
            cout << (x | (1LL << i)) << "\n";
        } 
        else if (type == 4) {
            ll x; int i; cin >> x >> i;
            // Tắt bit thứ i: dùng phép AND với bit NOT
            cout << (x & ~(1LL << i)) << "\n";
        } 
        else if (type == 5) {
            ll x; int i; cin >> x >> i;
            // Đảo bit thứ i: dùng phép XOR
            cout << (x ^ (1LL << i)) << "\n";
        } 
        else if (type == 6) {
            ll x; int n; cin >> x >> n;
            // Đảo ngược n bit đầu tiên và CHỈ lấy n bit đó
            // Mask gồm n bit 1: (1LL << n) - 1
            // Lưu ý: Nếu n=64, (1LL << 64) sẽ bị lỗi, nhưng thường n <= 62
            unsigned long long mask = (n == 64) ? ~0ULL : (1ULL << n) - 1;
            cout << ((~x) & mask) << "\n";
        } 
        else if (type == 7) {
            ll x, y; cin >> x >> y;
            // Nếu x AND y == 0 tức là không có bit nào cùng bật
            if ((x & y) == 0) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}

int main() {
    // Tăng tốc nhập xuất để xử lý 10^6 truy vấn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}