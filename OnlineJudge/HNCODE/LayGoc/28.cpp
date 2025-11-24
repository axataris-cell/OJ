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
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int z = (f + c) % 60;
	int y = (b + e) % 60;
	int x = a + d;
	if (f + c >= 60) ++y;
	if (b + e >= 60) ++x;
	cout << x << ' ' << y << ' ' << z << el;
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
