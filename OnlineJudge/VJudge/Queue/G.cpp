#include <bits/stdc++.h>
using namespace std;

int C[30][30];

// Precompute combinations
void buildC() {
    for (int n = 0; n < 30; n++) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; k++)
            C[n][k] = C[n-1][k-1] + C[n-1][k];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    buildC();
    string s;

    while (cin >> s) {
        int n = s.size();
        bool ok = true;

        // Check strictly increasing
        for (int i = 1; i < n; i++)
            if (s[i] <= s[i-1]) ok = false;

        if (!ok) {
            cout << 0 << "\n";
            continue;
        }

        int result = 0;

        // Count all words with smaller length
        for (int len = 1; len < n; len++)
            result += C[26][len];

        // Count words of same length lexicographically before s
        int prev = 0; // previous letter index
        for (int i = 0; i < n; i++) {
            int cur = s[i] - 'a' + 1;
            for (int c = prev + 1; c < cur; c++) {
                result += C[26 - c][n - i - 1];
            }
            prev = cur;
        }

        // Add itself
        result++;

        cout << result << "\n";
    }

    return 0;
}
