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
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	while (q--) {
		int x; cin >> x;
		
		for (int i = 0; i < n; i++) {
			if (a[i] == x) {
				cout << i + 1 << ' ';
				a.erase(a.begin() + i);
				a.insert(a.begin(), x);
				break;
			}
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
