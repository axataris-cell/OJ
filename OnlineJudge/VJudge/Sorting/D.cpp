#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[105];

void testcase() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n, [](int x, int y) {
		if (x % 10 != y % 10) return x % 10 < y % 10;
		else return x < y;
	});
	for (int i = 0; i < n; i++) cout << A[i] << ' ';
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
