#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}	

const int MAXN = 6005;
int A[MAXN] = {};

void testcase() {
	int n, l; cin >> n >> l;
	ll res = 0;
	ll cur = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (cur + A[i] <= l) {
			cur += A[i];
			res = max(res, l - cur);
		} else {
			cur = A[i];
			res = max(res, l - cur);
		}
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
