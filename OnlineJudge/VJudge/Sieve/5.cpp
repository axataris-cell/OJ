#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;
bool p[MAXN + 1];
vector<int> s;

void sieve() {
    for (int i = 2; i <= MAXN; i++) p[i] = true;

    for (int i = 2; i * i <= MAXN; i++) {
        if (p[i]) {
            for (long long j = 1LL * i * i; j <= MAXN; j += i) {
                p[j] = false;
            }
        }
    }

    // push toàn bộ primes vào vector
    for (int i = 2; i <= MAXN; i++) {
        if (p[i]) s.push_back(i);
    }
}

void testcase() {
    int n;
    cin >> n;

    int l = 0, r = s.size() - 1;

    while (l <= r) {
        long long sum = 1LL * s[l] + s[r];
        if (sum == n) {
            cout << s[l] << " " << s[r];
            return;
        }
        if (sum < n) l++;
        else r--;
    }

    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    testcase();
}
