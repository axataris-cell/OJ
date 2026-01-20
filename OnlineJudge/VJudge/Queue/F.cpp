#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	while (true) {
		int n, m; cin >> n >> m;
		if (n == 0 && m == 0) break;
		unordered_map<int, int> mp;
		while (n--) {
			int x; cin >> x;
			++mp[x];
		}
		int res = 0;
		while (m--) {
			int x; cin >> x;
			if (mp[x] != 0) ++res;
		}
		cout << res << el;
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
