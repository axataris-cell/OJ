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
	map<int, int> mp;
	int cnt = 0;
	while (n--) {
		string t; cin >> t;
		if (t == "add") {
			int x; cin >> x;
			if (mp[x] == 0) ++cnt;
			++mp[x];
		} else if (t == "del") {
			int x; cin >> x;
			if (mp[x] == 1) --cnt;
			if (mp[x] > 0) --mp[x];
		} else if (t == "count") {
			int x; cin >> x;
			cout << mp[x] << el;
		} else if (t == "size") {
			cout << cnt << el;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
