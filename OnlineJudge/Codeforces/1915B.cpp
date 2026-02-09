#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

void testcase() {
	string t[3];
	cin >> t[0] >> t[1] >> t[2];
	map<char, int> mp;
	for (int i = 0; i < 3; i++) {
		mp.clear();
		string s = t[i];
		for (int i = 0; i < 3; i++) ++mp[s[i]];
		for (int i = 'A'; i <= 'C'; i++) {
			if (!mp[i]) {
				cout << (char)i << el;
				return;
			}
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
