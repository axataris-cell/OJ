#include <iostream>
#include <unordered_map>
using namespace std;

using ll = long long;
unordered_map<ll,ll> memo;

ll f(ll n) {
    if (n == 1) return 1;
    if (memo.count(n)) return memo[n];

    if (n % 2 == 0) {
        return memo[n] = f(n / 2) + 1;
    } else {
        return memo[n] = f(n / 2) + f(n / 2 + 1);
    }
}

int main() {
    ll n;
    cin >> n;
    cout << f(n);
}
