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
	int n; cin >> n;
	vector<int> a(n); unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		++mp[a[i]];
	}
	int m; cin >> m;
	while (m--) {
		int x; cin >> x;
		if (mp[x]) cout << "YES" << el;
		else cout << "NO" << el;
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
