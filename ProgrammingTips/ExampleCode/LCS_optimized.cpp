#include <bits/stdc++.h>
using namespace std;

static int f[1005][1005];
static int pos_left[26][1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int m = a.size();
    int n = b.size();

    // tiền xử lý pos_left
    for (int cc = 0; cc < 26; cc++) {
        int last = -1;
        for (int j = 0; j < n; j++) {
            if (b[j] == 'A' + cc) last = j;
            pos_left[cc][j] = last;
        }
    }

    // f[m][0] = n-1, f[m][k>0] = -1
    f[m][0] = (n > 0 ? n - 1 : -1);
    for (int k = 1; k <= m; k++) f[m][k] = -1;

    // dp
    for (int i = m - 1; i >= 0; i--) {
        f[i][0] = (n > 0 ? n - 1 : -1);

        for (int k = 1; k <= m - i; k++) {

            int best = f[i+1][k];

            int t = f[i+1][k-1];
            if (t >= 0) {
                int pos = pos_left[a[i] - 'A'][t];
                if (pos >= 0) best = max(best, pos);
            }

            f[i][k] = best;
        }
    }

    // độ dài L
    int L = 0;
    for (int k = m; k >= 0; k--) {
        if (f[0][k] >= 0) {
            L = k;
            break;
        }
    }

    // truy vết
    string ans;
    ans.reserve(L);

    int i = 0, k = L;
    while (k > 0 && i < m) {
        if (f[i][k] == f[i+1][k]) {
            i++;
            continue;
        }

        ans.push_back(a[i]);
        i++;
        k--;
    }

    cout << ans;
}
