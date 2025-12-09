#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, long long> cnt;
    vector<int> order;
    int x;

    while (cin >> x) {
        if (cnt[x] == 0) {
            order.push_back(x);
        }
        cnt[x]++;
    }

    for (int v : order) {
        cout << v << " " << cnt[v] << "\n";
    }

    return 0;
}
