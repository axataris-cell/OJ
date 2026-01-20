#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	int n, q; cin >> n >> q;
	vector<int> A(n + 5, 0);
	vector<int> S(n + 5, 0);
	
	while (q--) {
		int l, r; cin >> l >> r;
		if (r > l) {
			++S[l]; --S[r + 1];
		} else {
			++S[r]; --S[n];
			--S[l + 1]; ++S[1];
		}
	}
	A[0] = 0;
	for (int i = 1; i <= n; i++) {
		A[i] = A[i - 1] + S[i];
	}
	
	sort(A.begin(), A.end(), greater<int>());
	
	int max = A[0];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cout << A[i] << el;
		if (A[i] == max) ++cnt;
		else break;
	}
	
	cout << max << ' ' << cnt;
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
