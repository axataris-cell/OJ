for (int mask = 0; mask < (1 << n); mask++) {
    dp[mask][0] = a[mask]; // trường hợp cơ sở
    for (int k = 1; k <= n; k++) {
        if (mask & (1 << (k - 1)))
            dp[mask][k] = dp[mask ^ (1 << (k - 1))][k - 1] + dp[mask][k - 1];
        else dp[mask][k] = dp[mask][k - 1];
    }
    f[mask] = dp[mask][n];
}

for (int mask = 0; mask < (1 << n); mask++) dp[mask][0] = a[mask]; // trường hợp cơ sở
for (int k = 1; k <= n; k++) {
    for (int mask = 0; mask < (1 << n); mask++) {
        if (mask & (1 << (k - 1)))
            dp[mask][k] = dp[mask ^ (1 << (k - 1))][k - 1] + dp[mask][k - 1];
        else dp[mask][k] = dp[mask][k - 1];
    }
}
for (int mask = 0; mask < (1 << n); mask++) f[mask] = dp[mask][n];