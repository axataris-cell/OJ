#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

ll f[100005] = {};

void testcase() {
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= 92; i++) {
		f[i] = f[i-1] + f[i-2];
//		cout << i << ' ' << f[i] << el;
	}
	
	ll a, b; cin >> a >> b;
	ll ia, ib;
	for (int i = 0; i <= 92; i++) {
		if (f[i] >= a) {
			ia = i;
			break;
		}
	}
	for (int i = 0; i <= 92; i++) {
		if (f[i] > b) {
			ib = i;
			break;
		}
	}
	
	cout << ib - ia;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
