#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int F[1005] = {};

void testcase() {
	string s; getline(cin, s);
	for (int i = 0; i < (int)s.length(); i++) ++F[tolower((int)s[i])];
	for (int i = 'a'; i <= 'z'; i++) {
		if (F[i] != 0) {
			cout << (char)i << ' ' << F[i] << el;
		}
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
