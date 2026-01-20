#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int m = a.size();
    int n = b.size();

    /* =========================
       1. Lưu vị trí xuất hiện
       ========================= */
    vector<int> occ[256];
    for (int i = 0; i < n; i++)
        occ[(unsigned char)b[i]].push_back(i);

    /* =========================
       2. DP
       dp[k] = vị trí j lớn nhất
       ========================= */
    vector<int> dp(m + 1, -1), ndp(m + 1, -1);
    dp[0] = n;

    // truy vết
    vector<vector<int>> take(m, vector<int>(m + 1, 0));
    vector<vector<int>> from(m, vector<int>(m + 1, -1));

    /* =========================
       3. DP
       ========================= */
    for (int i = m - 1; i >= 0; i--) {
        ndp = dp;

        auto &v = occ[(unsigned char)a[i]];

        for (int k = 1; k <= m; k++) {
            if (dp[k - 1] == -1 || v.empty()) continue;

            int t = dp[k - 1];

            auto it = lower_bound(v.begin(), v.end(), t);
            if (it == v.begin()) continue;
            --it;

            int j = *it;
            if (j > ndp[k]) {
                ndp[k] = j;
                take[i][k] = 1;
                from[i][k] = k - 1;
            }
        }
        swap(dp, ndp);
    }

    /* =========================
       4. Lấy độ dài LCS
       ========================= */
    int L = 0;
    for (int k = m; k >= 0; k--)
        if (dp[k] != -1) {
            L = k;
            break;
        }

    /* =========================
       5. Truy vết
       ========================= */
    string res;
    int k = L;
    for (int i = 0; i < m && k > 0; i++) {
        if (take[i][k]) {
            res.push_back(a[i]);
            k = from[i][k];
        }
    }

    cout << res << '\n';
    return 0;
}
