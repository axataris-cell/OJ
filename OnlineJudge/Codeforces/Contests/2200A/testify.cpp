#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXA = 1000005;
int min_prime[MAXA];

// Precompute smallest prime factor for each number up to 10^6
void sieve() {
    for (int i = 2; i < MAXA; ++i) {
        if (min_prime[i] == 0) {
            for (int j = i; j < MAXA; j += i) {
                if (min_prime[j] == 0) min_prime[j] = i;
            }
        }
    }
}

// Returns the prime p if x = p^k, otherwise returns -1
int get_prime_power_base(int x) {
    if (x <= 1) return 0;
    int p = min_prime[x];
    int temp = x;
    while (temp > 1 && temp % p == 0) temp /= p;
    return (temp == 1) ? p : -1;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    bool initially_sorted = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && a[i] < a[i - 1]) initially_sorted = false;
    }

    if (initially_sorted) {
        cout << "Bob" << endl;
        return;
    }

    // Check if all 1s are at the beginning
    bool seen_non_one = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            if (seen_non_one) {
                cout << "Alice" << endl;
                return;
            }
        } else {
            seen_non_one = true;
        }
    }

    // Check if every a_i > 1 is a prime power and the primes are non-decreasing
    vector<int> prime_bases;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 1) {
            int p = get_prime_power_base(a[i]);
            if (p == -1) {
                cout << "Alice" << endl;
                return;
            }
            prime_bases.push_back(p);
        }
    }

    for (int i = 0; i < (int)prime_bases.size() - 1; ++i) {
        if (prime_bases[i] > prime_bases[i + 1]) {
            cout << "Alice" << endl;
            return;
        }
    }

    cout << "Bob" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}