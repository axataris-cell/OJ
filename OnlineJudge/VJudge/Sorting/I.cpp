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
	int x;
	vector<pair<int, int>> a;
	while (cin >> x) {
		a.push_back({x, 0});
	}
	for (int i = 0; i < a.size(); i++) {
		a[i].second = a[i].first;
		while (a[i].second >= 10) {
			int temp = a[i].second;
			int sum = 0;
			while (temp != 0) {
				sum += temp % 10;
				temp /= 10;
			}
			a[i].second = sum;
		}
	}
	sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
		if (x.second != y.second) return x.second < y.second;
		else return x.first < y.first;
	});
	for (auto x : a) cout << x.first << ' ';
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
