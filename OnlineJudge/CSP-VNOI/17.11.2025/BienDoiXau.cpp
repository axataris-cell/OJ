#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int f[1000005] = {};
int g[1000005] = {};

void testcase() {
	string s; cin >> s;
	if (s[0] == 'A') {
		f[0] = 0;
		g[0] = 1;
	} else {
		f[0] = 1;
		g[0] = 0;
	}
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == 'A') {
			f[i] = f[i - 1];
			g[i] = min(g[i - 1] + 1, f[i - 1] + 1);
		} else {
			f[i] = min(f[i - 1] + 1, g[i - 1] + 1);
			g[i] = g[i - 1];
		}
	}
	cout << f[s.length() - 1];
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
