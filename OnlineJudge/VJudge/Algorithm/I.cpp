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
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	while (q--) {
		int f; cin >> f;
		
		int l = 0, r = n - 1;
		int res = 0;
		
		while (l <= r) {
			int m = (l + r) / 2;
			
			if (a[m] > f) r = m - 1;
			else if (a[m] < f) l = m + 1;
			else {
				res = m + 1;
				break;
			}
		}
		
		cout << res; 
		cout << el;
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
