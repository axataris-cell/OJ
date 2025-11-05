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
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	sort(A + 1, A + n + 1);
//	for (int i = 1; i <= n; i++) cout << A[i] << ' ';
//	cout << el;
	ll res = 0;
	for (int i = 1; i <= n; i += 2) {
		res += A[i + 1] - A[i];
//		cout << res << ' ' << i << el;
	}
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
