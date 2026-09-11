#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6;

long long fact[MAXN + 1], invFact[MAXN + 1];

// Lũy thừa nhanh (base^exp % MOD)
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Nghịch đảo mô-đun
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// Tiền xử lý O(N)
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN] = modInverse(fact[MAXN]);
    for (int i = MAXN - 1; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// Truy vấn O(1)
long long nCr_mod(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}