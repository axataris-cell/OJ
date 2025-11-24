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
	int n; cin >> n;
	cin.ignore();
	while (n--) {
		string s; getline(cin, s);
		vector<string> words;
		stringstream ss(s);
		string t;
		while (ss >> t) {
			words.push_back(t);
		}
		for (string &g : words) {
			g[0] = (char)toupper((int)g[0]);
			cout << g << ' ';
		}
		cout << el;
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
