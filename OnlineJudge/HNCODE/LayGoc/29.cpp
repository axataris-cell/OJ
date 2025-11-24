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
	string s; getline(cin, s); int n = s.length();
	bool strong = false;
	bool invalid = false;
	if (s.length() < 4) invalid = true;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ') {
			invalid = true;
			break;
		}
		if (s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?') {
			invalid = true;
			break;
		}
	}
	
	if (invalid) {
		cout << "Invalid";
		return;
	}
	
	for (int i = 0; i < n; i++) {
		++F[s[i]];
	}
	
	bool norm = false;
	bool high = false;
	bool num = false;
	
	for (int i = 'a'; i <= 'z'; i++) {
		if (F[i] != 0) {
			norm = true;
			break;
		}
	}
	
	for (int i = 'A'; i <= 'Z'; i++) {
		if (F[i] != 0) {
			high = true;
			break;
		}
	}
	
	for (int i = '0'; i <= '9'; i++) {
		if (F[i] != 0) {
			num = true;
			break;
		}
	}
	
	if (high && norm && num && s.length() >= 8) strong = true;
	
	if (strong) {
		cout << "Strong";
	}  else {
		cout << "Weak";
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
