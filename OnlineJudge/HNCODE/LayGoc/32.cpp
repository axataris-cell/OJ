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
	double x; cin >> x;
	double a = 0, b = 0;
	if (x > 0) {
		a = (int)x;
		b = x - a;
	} else {
		a = floor(x);
		b = x - a;
	}
	cout << a << el << b;
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
