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
		return x.first*x.second > y.first*y.second;
	});
	
	ld res = 0;
	
	for (int i = 0; i < n; i++) {
		res = max(a[i].first * a[i].second / 2.0L, res);
	}
	for (int i = 0; i < n - 1; i++) {
		int x = min(a[i].first, a[i].second);
		int y = min(a[i + 1].first, a[i + 1].second);
		int z = max(a[i].first, a[i].second);
		int t = max(a[i + 1].first, a[i + 1].second);
		
		res = max(res, (ld)min(z, t) * min(x, y));
	}
	
	cout << setprecision(1) << fixed << res;
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
