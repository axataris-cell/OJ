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
	vector<pii> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), [](pii x, pii y) {
		if (x.first != y.first) return x.first < y.first;
		return x.second > y.second;
	});
	for (pii x : a) cout << x.first << ' ' << x.second << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
