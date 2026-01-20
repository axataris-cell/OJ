// Ts TLE bitch

#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> dat;
vector<ll> res;

void dq(ll cur) {
    if (cur > 100000000) return;
    if (cur > 0) dat.push_back(cur);
    for (int d : {1, 3, 5, 7, 9})
        dq(cur * 10 + d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dq(0);
    sort(dat.begin(), dat.end());

    vector<vector<int>> byLen(9);
    for (int x : dat) {
        int len = to_string(x).size();
        byLen[len].push_back(x);
    }

    unordered_set<int> seen;
    seen.reserve(1000000);
    seen.max_load_factor(0.7);

    for (int lenA = 1; lenA <= 8; ++lenA) {
        for (int lenB = lenA; lenB <= 8; ++lenB) {
            for (int a : byLen[lenA]) {
                for (int b : byLen[lenB]) {
                    int sum = a + b;
                    if (sum > 200000000) break;
                    seen.insert(sum);
                }
            }
        }
    }

    res.assign(seen.begin(), seen.end());
    seen.clear();
    sort(res.begin(), res.end());

    string s;
    while (cin >> s) {
        if (s == "[END]") break;
        if (s == "[CASE]") {
            ll X; cin >> X;
            auto it = lower_bound(res.begin(), res.end(), X);
            if (it != res.end()) cout << *it << "\n";
            else cout << -1 << "\n";
        }
    }
}
