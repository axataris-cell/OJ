#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    s += s;

    vector<int> pref(2*n + 1);

    for (int i = 1; i <= 2*n; i++) {
        pref[i] = pref[i-1] + (s[i-1] == '(' ? 1 : -1);
    }

    deque<int> dq;
    int res = 0;

    for (int i = 1; i <= 2*n-1; i++) {

        while (!dq.empty() && pref[dq.back()] >= pref[i])
            dq.pop_back();

        dq.push_back(i);

        while (!dq.empty() && dq.front() <= i-n)
            dq.pop_front();

        if (i >= n) {
            int l = i-n+1;

            if (pref[i] - pref[l-1] == 0 &&
                pref[dq.front()] - pref[l-1] >= 0)
                res++;
        }
    }

    cout << res;
}