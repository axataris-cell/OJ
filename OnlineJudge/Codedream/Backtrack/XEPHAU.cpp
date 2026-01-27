#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int r, c;
    long long val;
};

int n, k;
long long a[15][15];
bool row[15], col[15], diag1[30], diag2[30];
vector<Cell> cells;
long long ans = 0;

void backtrack(int idx, int placed, long long sum) {
    if (placed == k) {
        ans = max(ans, sum);
        return;
    }
    if (idx == (int)cells.size()) return;

    long long ub = sum;
    int need = k - placed;
    for (int i = idx; i < (int)cells.size() && need > 0; i++) {
        int r = cells[i].r;
        int c = cells[i].c;
        if (!row[r] && !col[c] && !diag1[r - c + n] && !diag2[r + c]) {
            ub += cells[i].val;
            need--;
        }
    }
    if (need > 0 || ub <= ans) return;

    int r = cells[idx].r;
    int c = cells[idx].c;
    if (!row[r] && !col[c] && !diag1[r - c + n] && !diag2[r + c]) {
        row[r] = col[c] = diag1[r - c + n] = diag2[r + c] = true;
        backtrack(idx + 1, placed + 1, sum + cells[idx].val);
        row[r] = col[c] = diag1[r - c + n] = diag2[r + c] = false;
    }


    backtrack(idx + 1, placed, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            cells.push_back({i, j, a[i][j]});
        }

    sort(cells.begin(), cells.end(), [](const Cell &x, const Cell &y) {
        return x.val > y.val;
    });

    backtrack(0, 0, 0);
    cout << ans << '\n';
    return 0;
}
