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
    for (int i = 2; i <= n; i++) is_prime[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i] == i) {
            for (int j = i * i; j <= n; j += i)
                if (is_prime[j] == j) is_prime[j] = i;
        }
    }
}

int A[1000005] = {};
void testcase() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) {
		int x = A[i];
		int cnt = 0;
		while (x > 1) {
			++cnt;
			x /= is_prime[x];
			if (cnt > 3) break;
		}		
		if (cnt == 3) cout << "YES" << el;
		else cout << "NO" << el;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();
	sieve(1e6);
	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
