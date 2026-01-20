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
	pair<int, int> temp = {};
	vector<pair<int, int>> a;
	int x; int y;
	while (cin >> x) {
		cin >> y;
		a.push_back({x, y});
	}
	sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
		if (x.first != y.first) return x.first < y.first;
		else return x.second > y.second;
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
