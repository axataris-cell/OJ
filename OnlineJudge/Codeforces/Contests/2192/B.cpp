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
	int n; cin >> n;
	string s; cin >> s;
	
	int cnt0 = 0;
	int cnt1 = 0;
	vector<int> res1;
	vector<int> res0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			++cnt0;
			res0.push_back(i);
		}
		else {
			++cnt1;
			res1.push_back(i);
		}
	}
	if (cnt1 % 2 == 0) {
		cout << res1.size() << el;
		for (auto x : res1) cout << x + 1 << ' ';
		cout << el;
	} else {
		if (cnt0 % 2 == 0) {
			cout << -1 << el;
			return;
		}
		cout << res0.size() << el;
		for (auto x : res0) cout << x + 1 << ' ';
		cout << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
