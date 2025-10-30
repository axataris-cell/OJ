#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> A[i][j];

    for (int s = 2; s <= n + m; s++) {
        // s = i + j
        vector<pair<int, int>> diag;
        for (int i = 1; i <= n; i++) { // Ch?n i t? 1  ->  n
            int j = s - i;
            if (j >= 1 && j <= m) // Ch?n j t? 1  ->  m
                diag.push_back({i, j}); 
        }

        if (s % 2 == 0)
            reverse(diag.begin(), diag.end());

        for (auto [i, j] : diag)
            cout << A[i][j] << " ";
    }
}
