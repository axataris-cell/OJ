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
	int n; cin >> n;
	int n2 = 0, n5 = 0;
	while (n % 2 == 0) {
		++n2; n /= 2;
	}
	while (n % 5 == 0) {
		++n5; n /= 5;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
