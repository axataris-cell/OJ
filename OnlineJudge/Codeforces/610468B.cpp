#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("FARGCD.INP", "r", stdin);
	freopen("FARGCD.OUT", "w", stdout);
}

void testcase() {
	ll l, r; cin >> l >> r;
	if (l == 1) {
		cout << r - 1; return;
	}
	
	while (l <= r && gcd(l, r) != 1) {
		++l;
	}
	
	cout << r - l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
