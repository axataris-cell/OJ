#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	int k; cin >> k;
	ll res = -1;
	
	ll r2 = 0, r3 = 0;
	while (k % 2 == 0 && k) {
		++r2;
		k /= 2;
	}
	while (k % 3 == 0 && k) {
		++r3;
		k /= 3;
	}
	
	if (k != 1 || r3 > r2) cout << res;
	else {
		cout << 2*r2 - r3;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
