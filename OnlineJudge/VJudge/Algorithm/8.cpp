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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	ll cnt = 0;
	int l = 0, r = 1;
	
	while (r < n) {
		if (a[r] - a[l] < k) {
			++r;
		} else if (a[r] - a[l] > k) {
			++l;
		} else {
			++cnt; ++r; ++l;
		}
		if (l > r - 1) l = r - 1;
	}
	cout << cnt;
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
