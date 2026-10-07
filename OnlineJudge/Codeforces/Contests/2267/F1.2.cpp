#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> ans;

    // Mo ph?ng t?i ?a cho ??n khi m?ng toan s? 0
    while (true) {
        long long min_val = a[0];
        long long max_val = a[0];
        for (int i = 1; i < n; ++i) {
            min_val = min(min_val, a[i]);
            max_val = max(max_val, a[i]);
        }

        ans.push_back(max_val - min_val);

        // Khi t?t c? ph?n t? b?ng 0 thi cac b??c sau ??u b?ng 0
        if (max_val == 0 || ans.size() > 100) {
            break;
        }

        // T?o t?t c? n*(n-1)/2 c?p XOR
        vector<long long> b;
        b.reserve(n * (n - 1) / 2);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                b.push_back(a[i] ^ a[j]);
            }
        }

        // L?y n ph?n t? nh? nh?t
        nth_element(b.begin(), b.begin() + n, b.end());
        sort(b.begin(), b.begin() + n);

        for (int i = 0; i < n; ++i) {
            a[i] = b[i];
        }
    }

    // Tr? l?i cac truy v?n
    for (int i = 0; i < q; ++i) {
        long long x;
        cin >> x;
        if (x < (long long)ans.size()) {
            cout << ans[x] << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}

int main() {
    // T?i ?u hoa I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
