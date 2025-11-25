#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int F[10] = {};

void testcase() {
	string s; cin >> s;
	int n = s.length();
	
	int m = stoll(s) % 4;
	
	int cnt = 0;
	if (n == 2) {
		s = "12";
	} else if (n == 3 && s[0] == '1') {
		s = "100";
	} else {
		if (m == 0) {
			if (s[0] != '1') {
				s[0] = '1'; ++cnt;
			}
			for (int i = 1; i < n; i++) {
				if (s[i] != '0') {
					s[i] = '0';
					++cnt;
				}
				if (cnt == 2) break;
			}
		} else if (m == 1) {
			if ((int)(s[n - 2] - '0') & 1) {
				s[n - 1] = '2'; ++cnt;
			} else {
				s[n - 1] = '0'; ++cnt;
			}
			if (s[0] != '1') {
				s[0] = '1';
				++cnt;
			}
			if (cnt < 2) {
				for (int i = 1; i < n - 1; i++) {
					if (s[i] != '0') {
						s[i] = '0'; ++cnt;
						break;
					}
					if (cnt > 2) break;
				}
			}
		} else if (m == 2) {
			if (s[n - 2] != '0') {
				if (s[n - 1] == '0' || s[n - 1] == '4' || s[n - 1] == '8') {
					s[n - 2] = '0'; ++cnt;
				} else {
					s[n - 2] = '1'; ++cnt;
				}
			} else {
				s[n - 1] = 0; ++cnt;
			}
			if (s[0] != '1') {
				s[0] = '1';
				++cnt;
			}
			if (cnt < 2) {
				for (int i = 1; i < n - 1; i++) {
					if (s[i] != '0') {
						s[i] = '0'; ++cnt;
						break;
					}
					if (cnt > 2) break;
				}
			}
		} else if (m == 3) {
			if ((int)(s[n - 2] - '0') & 1) {
				s[n - 1] = '2'; ++cnt;
			} else {
				s[n - 1] = '0'; ++cnt;
			}
			if (s[0] != '1') {
				s[0] = '1';
				++cnt;
			}
			if (cnt < 2) {
				for (int i = 1; i < n - 1; i++) {
					if (s[i] != '0') {
						s[i] = '0'; ++cnt;
						break;
					}
					if (cnt > 2) break;
				}
			}
		}
	}
	
	cout << s;
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
