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
	ll n; cin >> n;
	ll a = n / 5;
	if (n % 5 == 0) cout << a;
	else if (n % 5 == 1) {
		cout << a + 1;
	} else if (n % 5 == 2) {
		cout << a + 1;
	} else if (n % 5 == 3) {
		cout << a + 1;
	} else if (n % 5 == 4) {
		cout << a + 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
