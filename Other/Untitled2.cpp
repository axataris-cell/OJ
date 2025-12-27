#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	string x, y;
	int a = 'a'; int b = 'z';
	for (int i = 0; i <= 1e2; i++) {
		x.push_back(rand() % (b - a + 1) + a);
	}
	for (int i = 0; i <= 1e2; i++) {
		y.push_back(rand() % (b - a + 1) + a);
	}
	cout << x << el << y;
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
