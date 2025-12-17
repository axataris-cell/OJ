#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    if (n == 1) {
        cout << 1 << " " << 1;
        return 0;
    }

    ll cur_diff = A[2] - A[1];
    int cur_len = 2;
    int best_len = 2, best_pos = 1;

    for (int i = 3; i <= n; i++) {
        ll d = A[i] - A[i - 1];
        if (d == cur_diff) {
            cur_len++;
        } else {
            cur_diff = d;
            cur_len = 2;
        }

        // Nếu bằng hoặc lớn hơn thì lấy đoạn sau cùng
        if (cur_len >= best_len) {
            best_len = cur_len;
            best_pos = i - cur_len + 1;
        }
    }

    cout << best_len << " " << best_pos << el;
    return 0;
}
