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
	int n; cin >> n; vector<int> a(n), even; for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) even.push_back(a[i]);
	}
	int x; cin >> x;
	x = min(x, (int)even.size());
	for (int i = 0; i < x; i++) cout << even[i] << ' ';
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
