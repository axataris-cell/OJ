#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

const int MAXN = 6005;
int A[MAXN] = {};
int f[MAXN] = {};

void testcase() {
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	for (int i = 1; i <= n; i++) {
		f[i] = l + 1;
		int j = i, S = A[i];
		while (j > 0 && S <= l) {
			f[i] = min(f[i], max(f[j - 1], l - S));
			S += A[--j];
		}
	}
	cout << f[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
