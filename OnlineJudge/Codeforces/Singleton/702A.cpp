#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

ll A[100005] = {};

void testcase() {
	int n; cin >> n;
	
	ll cur = 0;
	int cnt = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i] > cur) {
			cur = A[i];
			++cnt;	
		} else {
			res = max(res, cnt);
			cnt = 1;
			cur = A[i];
		}
//		cout << cnt << ' ' << res << el;
	}
	res = max(res, cnt);
	cout << res;
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
