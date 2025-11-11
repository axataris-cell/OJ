#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int F[1000005] = {};

void testcase() {
	string s; cin >> s;
	
	int p = 0;
	int cnt = 0;
	
	F[0] = 0;
	cout << F[0] << ' ';
	for (int i = 1; i < s.length(); i++) {
		if (s[p] == s[i]) {
			++cnt; ++p;
		} else {
			cnt = 0; p = 0;
			if (s[p] == s[i]) {
				++cnt; ++p;
			}
		}
		F[i] = cnt;
		cout << F[i] << ' ';
	}
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
