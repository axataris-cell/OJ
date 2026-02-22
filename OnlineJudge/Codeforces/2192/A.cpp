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

/*
1
4
abbc
*/

void testcase() {
	int n; cin >> n;
	string s; cin >> s;
	s = s + s;
//	cout << s << el;
	deque<pair<char, int>> dq;
	int res = 0;

	for (int i = 0; i < 2 * n; i++) {
//		cout << dq.front().first << ' ' << dq.front().second << el;
		if (dq.empty()) {
			dq.push_back({s[i], 1});
			continue;
		}
		if (s[i] == dq.front().first) {
			++dq.front().second;
		} else {
			dq.push_front({s[i], 1});
		}
		
		if (i >= n) {
			if (dq.back().second == 1) dq.pop_back();
			else {
				--dq.back().second;
			}
		}
		res = max(res, (int)dq.size());
	}
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
