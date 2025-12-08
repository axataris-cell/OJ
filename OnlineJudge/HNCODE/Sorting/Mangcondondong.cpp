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
	int n, q; cin >> n >> q;
	vector<int> a(n), f(n, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) f[i] = a[i] + f[i - 1];
	while (q--) {
		int x; cin >> x;
		if (x == 1) {
			int k; cin >> k;
			a.push_back(k);
			f[a.size()]
		} else if (x == 2) {
			if (!a.empty()) a.pop_back();
		} else if (x == 3) {
			int l, r; cin >> l >> r;
		}
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
