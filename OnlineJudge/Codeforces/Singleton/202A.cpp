#include <bits/stdc++.h>
using namespace std;

bool better(const string &a, const string &b) {
	int i = 0, j = 0;
	while (i < a.length() && j < b.length()) {
		if (a[i] != b[j]) return a[i] > b[j];
		++i; ++j;
	}
	return a.length() > b.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size();

    vector<vector<string>> dp(n, vector<string>(n, ""));

    for (int i = 0; i < n; i++) dp[i][i] = string(1, s[i]);

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;

            string best = dp[l + 1][r];
            if (better(dp[l][r - 1], best)) best = dp[l][r - 1];

            if (s[l] == s[r]) {
                string mid = (l + 1 <= r - 1) ? dp[l + 1][r - 1] : "";
                string cand = s[l] + mid + s[r];
                if (better(cand, best)) best = cand;
            }

            dp[l][r] = best;
        }
    }

    cout << dp[0][n - 1] << "\n";
    return 0;
}
