#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

map<char, string> mp;

void testcase() {
	string s; cin >> s;
	int i = 1, j = 0;
	for (char c : s) {
		if (j < 5) ++j;
		else {
			++i;
			j = 1;
		}
		mp[c] = to_string(i*10 + j);
	}
	
	for (int i = 'a'; i <= 'z'; i++) cout << mp[(char)i] << ' ';
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
