#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int F[500] = {};

void testcase() {
	int n; cin >> n;
	cout << F[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();
	F[1] = 1;
	F[2] = 2;
	for (int i = 3; i <= 30; i++) {
		F[i] = F[i - 1] + F[i - 2] + 1;
	}

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
