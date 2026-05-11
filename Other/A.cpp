#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define null nullptr
#define pb push_back
#define len length
#define ll long long
#define el '\n'

using namespace std;

vector<vector<int>> prefsuff(const string& S1, const string& S2, int n) {
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (S1[x] == S2[y]) {
                C[x][y] = 1 + ((x > 0 && y > 0) ? C[x - 1][y - 1] : 0);
            }
        }
    }

    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            int mx = 0;

            for (int y = j; y < n; y++) {
                int len = C[i - 1][y];

                if (y - j + 1 < len)
                    len = y - j + 1;

                mx = max(mx, len);
            }

            f[i][j] = max(f[i - 1][j], mx);
        }
    }

    return f;
}

vector<vector<int>> suffpref(const string& S1, const string& S2, int n) {
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int x = n - 1; x >= 0; x--) {
        for (int y = n - 1; y >= 0; y--) {
            if (S1[x] == S2[y]) {
                C[x][y] = 1 + ((x < n - 1 && y < n - 1) ? C[x + 1][y + 1] : 0);
            }
        }
    }

    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int k = 1; k <= n; k++) {
            int mx = 0;

            for (int y = 0; y < k; y++) {
                int len = C[i][y];

                if (k - y < len)
                    len = k - y;

                mx = max(mx, len);
            }

            f[i][k] = max(f[i + 1][k], mx);
        }
    }

    return f;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(null);

    int n;
    cin >> n;

    string X, Y, Z;
    cin >> X >> Y >> Z;

    vector<vector<int>> f_A = prefsuff(X, Y, n);
    vector<vector<int>> f_B = suffpref(X, Z, n);
    vector<vector<int>> f_C = suffpref(Z, Y, n);

    int ans = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int max_bc = 0;

            for (int k = 0; k <= n; k++) {
                max_bc = max(max_bc, f_B[i][k] + f_C[k][j]);
            }

            ans = max(ans, f_A[i][j] + max_bc);
        }
    }

    cout << ans << el;
}