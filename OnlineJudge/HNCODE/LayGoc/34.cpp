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
	string p; cin >> p;
	string s = "";
	int t = 0;
	while (t < p.length()) {
		if (p[t] == '9') {
			s += (char)(stoi(p.substr(t, 2)));
			t += 2;
		} else {
			s += (char)(stoi(p.substr(t, 3)));
			t += 3;
		}
	}
	cout << s;
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
