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
	int l, r, m;
	cin >> l >> r >> m;
	int res = m - 1;
	
	for (int i = l; i < r; i++) {
		for (int j = i + 1; j <= r; j++) {
			res = min(res, i*j % m);
		}
	}
	
	cout << res;
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
