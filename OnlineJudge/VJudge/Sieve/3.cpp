#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int is_prime[1000005] = {};

void sieve(int n) {
    for (int i = 2; i <= n; i++)
        is_prime[i] = i;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] == i) {
            for (int j = i * 2; j <= n; j += i)
                is_prime[j] = i;
        }
    }
}

void testcase() {
	int n; cin >> n;
	unordered_map<int, int> freq;
	while (n != 1) {
		++freq[is_prime[n]];
		n /= is_prime[n];
	}
	ll x = 1;
	for (auto n : freq) {
		if (freq[n.first] % 2 == 1) x *= n.first; 
	}
	cout << x << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();
	sieve(1e6);
	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
