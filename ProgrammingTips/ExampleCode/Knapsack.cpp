for (auto [w, v] : items)
    for (int j = W; j >= w; j--)
        dp[j] = max(dp[j], dp[j - w] + v);

for (auto [w, v] : items)
    for (int x = V; x >= v; x--)
        dp[x] = min(dp[x], dp[x - v] + w);

//subset sum rolling
vector<bool> ndp = dp;

for (int s = 0; s + a[i] <= S; s++)
    if (dp[s])
        ndp[s + a[i]] = true;

dp = ndp;

//subset sum
