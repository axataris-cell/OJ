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
	vector<int> type[3];
	for (int i = 1; i <= n; i++) {
		int m; cin >> m;
		string s; cin >> s;
		if (s[0] == '1' && s[1] == '1') type[0].push_back(m);
		if (s[0] == '1' && s[1] == '0') type[1].push_back(m);
		if (s[0] == '0' && s[1] == '1') type[2].push_back(m);
	}
	for (int i = 0; i < 3; i++) sort(type[i].begin(), type[i].end());
	int res = INT_MAX;
	if (type[0].size()) res = type[0][0];
	if (type[1].size() && type[2].size()) res = min(res, type[1][0] + type[2][0]);
	
	if (res != INT_MAX) cout << res << el;
	else cout << -1 << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
