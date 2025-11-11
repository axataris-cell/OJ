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
	string s; cin >> s;
	string x; cin >> x;
	
	ll res = 0;
	for (int i = 0; i < s.length() - x.length() + 1; i++) {
//		cout << s.substr(i, x.length()) << ' ' << res << el;
		if (s.substr(i, x.length()) == x) {
			++res;
			i += x.length() - 1;
		}
	}
	
	cout << res;
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
