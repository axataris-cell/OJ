#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int MAXN = 100005;
int A[MAXN] = {};

void testcase() {
	int n, k; cin >> n >> k; // k là giáp
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);
	
	ll res = 0;
	for (int i = 0; i < n - 1; i++) {
		res += A[i];
	}
	res += max(0, A[n - 1] - k);
	++res;
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
