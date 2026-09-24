#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    ll total_ones = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            total_ones += grid[i][j];
        }
    }

    // pref[i][j] is sum of ones in row i from column 0 to j-1
    vector<vector<int>> pref(n, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pref[i][j + 1] = pref[i][j] + grid[i][j];
        }
    }

    // dp_min[i][j], dp_max[i][j] store the range of ones in part 'a'
    // when the cut reaches point (i, j)
    // Point (i, j) means i 'D' moves and j 'R' moves have been made.
    vector<vector<int>> dp_min(n + 1, vector<int>(m + 1, 1e9));
    vector<vector<int>> dp_max(n + 1, vector<int>(m + 1, -1e9));

    dp_min[0][0] = dp_max[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (dp_min[i][j] > dp_max[i][j]) continue;
            
            // Move Right
            if (j < m) {
                dp_min[i][j + 1] = min(dp_min[i][j + 1], dp_min[i][j]);
                dp_max[i][j + 1] = max(dp_max[i][j + 1], dp_max[i][j]);
            }
            // Move Down
            if (i < n) {
                int ones_added = pref[i][j];
                dp_min[i + 1][j] = min(dp_min[i + 1][j], dp_min[i][j] + ones_added);
                dp_max[i + 1][j] = max(dp_max[i + 1][j], dp_max[i][j] + ones_added);
            }
        }
    }

    int target = total_ones / 2;
    int best_a = -1;
    ll max_prod = -1;

    // In this specific problem, any value in [dp_min, dp_max] is reachable
    // because the "ones_added" changes by at most 1 when moving the cut.
    for (int a = dp_min[n][m]; a <= dp_max[n][m]; ++a) {
        ll current_prod = (ll)a * (total_ones - a);
        if (current_prod > max_prod) {
            max_prod = current_prod;
            best_a = a;
        }
    }

    cout << max_prod << "\n";

    // Backtrack to find the path
    string path = "";
    int curr_i = n, curr_j = m, curr_a = best_a;
    while (curr_i > 0 || curr_j > 0) {
        // Try coming from Left (R move)
        if (curr_j > 0 && curr_a >= dp_min[curr_i][curr_j - 1] && curr_a <= dp_max[curr_i][curr_j - 1]) {
            path += 'R';
            curr_j--;
        } else {
            // Must have come from Top (D move)
            path += 'D';
            curr_i--;
            curr_a -= pref[curr_i][curr_j];
        }
    }
    reverse(path.begin(), path.end());
    cout << path << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}