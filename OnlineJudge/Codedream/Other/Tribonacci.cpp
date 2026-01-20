#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'

ll A[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];

    if (n < 4) {
        cout << accumulate(A + 1, A + n + 1, 0LL);
        return 0;
    }

    int len = 3;
    ll sum = A[1] + A[2] + A[3];

    int best_len = 0;
    ll best_sum = 0;

    for (int i = 4; i <= n; i++) {
        if (A[i] == A[i - 1] + A[i - 2] + A[i - 3]) {
            len++;
            sum += A[i];
        } else {
            if (len >= 4) {
                if (len > best_len || (len == best_len && sum > best_sum)) {
                    best_len = len;
                    best_sum = sum;
                }
            }
            len = 3;
            sum = A[i - 2] + A[i - 1] + A[i];
        }
    }

    if (len >= 4) {
        if (len > best_len || (len == best_len && sum > best_sum)) {
            best_len = len;
            best_sum = sum;
        }
    }

    cout << best_sum << el;
    return 0;
}
