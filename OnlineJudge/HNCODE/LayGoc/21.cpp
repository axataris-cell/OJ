#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

ll F[1005] = {};

void testcase() {
	int n; cin >> n;
	cout << F[n] << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();
	F[0] = 0; F[1] = 1;
	for (int i = 2; i <= 50; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
	
	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
