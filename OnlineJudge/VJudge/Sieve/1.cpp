#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

unordered_map<int, bool> is_prime;

void sieve(int n) {
    for (int i = 2; i <= n; i++)
        is_prime[i] = true;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
void testcase() {
	int m, n; cin >> m >> n;
	int cnt = 0;
	for (int i = m; i <= n; i++) {
		if (i > 1e6 + 5) {
			for (int j = 2; j <= sqrt(i); i++) {
				if (is_prime[j]) {
					if (i % j == 0) break;
				}
			}
		} else {
			if (is_prime[i]) {
				cout << i << el;
			}
		}
	}
	cout << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();
	
	sieve(1000005);
	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
