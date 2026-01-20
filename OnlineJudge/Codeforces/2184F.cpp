#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> deg(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
        }

        int leaf = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1) leaf++;
        }

        if (leaf >= 3) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
