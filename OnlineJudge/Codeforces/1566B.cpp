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
	string s; cin >> s;
	int cnt = 0;
	vector<int> parts;
	parts.push_back(0);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') parts[parts.size() - 1]++;
		else if (s[i] == '1' && parts[parts.size() - 1] != 0) parts.push_back(0);
	}
	cerr << "DEBUG: ";
	for (auto x : parts) {
		cerr << x << ' ';
		if (x != 0) ++cnt;
	}
	cerr << el;
	cout << min(cnt, 2) << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
