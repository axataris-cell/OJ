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
	int n; cin >> n; vector<int> f(n);
	int a, b, c, d; cin >> a >> b >> c >> d;
	
	for (int i = 0; i < n; i++) {
		f[i] = i + 1;
	}
	sort(f.begin() + a - 1, f.begin() + b, greater<int>());
	reverse(f.begin() + c - 1, f.begin() + d);
	
	for (auto x : f) cout << x << ' ';
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
