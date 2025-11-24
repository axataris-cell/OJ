#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int MAX = 1857215;

void testcase() {
	ll s = 10000;
	cout << "10000 1" << el;
	for (int i = 2; i < 100; i++) {
		MAX -= s;
		s *= 2;
		cout << s << ' ' << i << el;
		if (s > MAX) break;
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
