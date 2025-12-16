#include <bits/stdc++.h>
#define int long long
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
const int MAXN = 2e5 + 5;

int a[MAXN];
int n, k;

bool check(int x) {
	int last = a[0], cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - last >= x) {
			last = a[i];
			cnt++;
		}
	}
	return cnt >= k;
}

void testcase() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	
	int l = 0, r = a[n - 1] - a[0];
	int res = 0;
	
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(m)) {
			res = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	
	cout << res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
