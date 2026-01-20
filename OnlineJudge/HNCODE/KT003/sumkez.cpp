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
	int n, k, b; cin >> n >> k >> b; ll res = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int cnt = 0;
	
	--b;
	b %= n;
	
	while (cnt < k) {
		res += a[b]; ++cnt; ++b;
		b %= n;
	}
	
	cout << res;
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
