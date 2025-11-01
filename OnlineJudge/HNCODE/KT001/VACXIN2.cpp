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
	ld n, m; cin >> n >> m;
	ld pa, pb; cin >> pa >> pb;
	
	int res = 0;
	if (m < n) {
		res = ceil((n - m)/(pa + pb));
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
