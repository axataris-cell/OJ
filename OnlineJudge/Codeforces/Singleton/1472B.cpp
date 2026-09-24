#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[105] = {};

void testcase() {
	int n; cin >> n;
	ll te = 0;
	ll to = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i] & 1) ++to;
		else ++te;
	}
	
	if (te & 1) {
		if (to >= 2 && to % 2 == 0) {
			cout << "YES" << el;
		} else {
			cout << "NO" << el;
		}
	} else {
		if (to & 1) cout << "NO" << el;
		else cout << "YES" << el;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
