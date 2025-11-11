#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[100005] = {};
int S[100005] = {};
int B[100005] = {};

void testcase() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		S[i] = A[i] - A[i - 1];
	}
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		++S[l]; --S[r + 1];
	}
	
	B[1] = S[1]; cout << B[1] << ' ';
	for (int i = 2; i <= n; i++) {
		B[i] = S[i] + B[i - 1];
		cout << B[i] << ' ';
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
