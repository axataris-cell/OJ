#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int z[1000005] = {};

void testcase() {
	string s; cin >> s;
	z[0] = 0;
	
	int L = 0, R = 0;
	for (int i = 1; i < s.length(); i++) {
		if (i <= R) z[i] = min(R - i + 1, z[i - L]);
		
		while (i + z[i] < s.length() && s[z[i]] == s[i + z[i]]) ++z[i];
		
		if (i + z[i] - 1 > R) {
			L = i;
			R = i + z[i] - 1;
		}
	}
	
	for (int i = 1; i < s.length(); i++) cout << z[i] << ' ';
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
