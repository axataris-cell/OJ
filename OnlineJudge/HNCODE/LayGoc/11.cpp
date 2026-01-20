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
	int x, y; cin >> x >> y;
	--x; 
	ll res = 0;
	for (int i = x; i <= x + y - 1; i++) {
		if (!(i % 7 == 6 || i % 7 == 0)) ++res;
	}
	cout << res;
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
