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
	vector<int> a;
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		if (n == 0) {
			int x; cin >> x;
			a.push_back(x);
		} else if (n == 1) {
			int x; cin >> x;
			cout << a[x] << el;
		} else {
			if (!a.empty()) a.pop_back();
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
