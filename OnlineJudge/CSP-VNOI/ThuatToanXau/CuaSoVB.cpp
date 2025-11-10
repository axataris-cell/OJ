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
	string n; getline(cin, n);
	string p; cin >> p;
	int k; cin >> k;
	
	vector<pair<int, int>> pos;
	for (int i = 0; i < n.length() - p.length() + 1; i++) {
		if (n.substr(i, p.length()) == p) pos.push_back({i, i + p.length() - 1});
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
