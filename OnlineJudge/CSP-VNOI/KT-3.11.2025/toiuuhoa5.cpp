#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[1000005] = {};

void testcase() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	
	ll minA = *min_element(A, A + n);
	ll maxA = *max_element(A, A + n);
	
	if (minA == maxA) {
		cout << 1 << el;
		return;
	}
	
	int lmn = -1, lmx = -1;
	int res = n + 1;
	
	for (int i = 0; i < n; i++) {
		if (A[i] == minA) {
			lmn = i;
			if (lmx != -1) res = min(res, i - lmx + 1);
		}
		if (A[i] == maxA) {
			lmx = i;
			if (lmn != -1) res = min(res, i - lmn + 1);
		}
	}
	
	cout << res << el;

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
