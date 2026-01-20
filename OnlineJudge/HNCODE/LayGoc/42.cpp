#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 10000000;
    vector<char> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; 1LL * i * i <= MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }

    int N;
    cin >> N;
    if (N >= 0 && N <= MAX && isPrime[N]) cout << "True\n";
    else cout << "False\n";
}
