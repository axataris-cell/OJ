#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;

long long A[MAXN + 5];
long long dp[MAXN + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> A[i];

    dp[1] = 0;
    if (n >= 2) dp[2] = abs(A[2] - A[1]);
    if (n >= 3) {
        dp[3] = min(dp[2] + abs(A[3] - A[2]),
                    dp[1] + abs(A[3] - A[1]));
    }

    for (int i = 4; i <= n; i++) {
        dp[i] = min({
            dp[i-1] + abs(A[i] - A[i-1]),
            dp[i-2] + abs(A[i] - A[i-2]),
            dp[i-3] + abs(A[i] - A[i-3])
        });
    }

    cout << dp[n];
}
