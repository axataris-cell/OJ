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
	F[0] = 0;
	
	for (int i = 1; i < s.length(); i++) {
		int j = F[i - 1];
		
		while (j > 0 && s[i] != s[j]) j = F[j - 1];
		if (s[i] == s[j]) ++j;
		
		F[i] = j;
	}
	
	for (int i = 0; i < s.length(); i++) cout << F[i] << ' ';
	cout << el;
	for (int i = 0; i < s.length(); i++) cout << s[i] << ' ';
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
