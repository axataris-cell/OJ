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
	int n; cin >> n;
	vector<pair<string, string>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	
	sort(a.begin(), a.end(), [](pair<string, string> x, pair<string, string> y) {
		if (x.second != y.second) return x.second < y.second;
		else return x.first < y.first;
	});
	for (auto x : a) cout << x.first << ' ' << x.second << el;
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
