#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1505;
int n;
int a[MAXN][MAXN];
int L[MAXN][MAXN], R[MAXN][MAXN];
int res[2*MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    // DP L: từ (1,1) đi xuống và sang phải
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int best = 0;
            if (i > 1) best = max(best, L[i-1][j]);
            if (j > 1) best = max(best, L[i][j-1]);
            L[i][j] = best + 1; // 1 là chính ô này
        }

    // DP R: từ (n,n) đi lên và sang trái
    for (int i = n; i >= 1; --i)
        for (int j = n; j >= 1; --j) {
            int best = 0;
            if (i < n) best = max(best, R[i+1][j]);
            if (j < n) best = max(best, R[i][j+1]);
            R[i][j] = best + 1;
        }

    // Tính độ lặp
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int k = L[i][j] + R[i][j] - 1;
            res[k]++;
        }

    // In kết quả
    for (int k = 1; k <= 2*n-1; ++k)
        cout << res[k] << "\n";

    return 0;
}