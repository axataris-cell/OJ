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
	string s; getline(cin, s);
	string a = "", b = "";
	
	for (char c : s) {
		if (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E') a += c;
		else if (c == ' ') a += '&';
		else b += c;
	}
	reverse(b.begin(), b.end());
	cout << a << b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
