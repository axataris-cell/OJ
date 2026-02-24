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
	vector<pii> r(n + 1, {0, 0});
	for (int i = 1; i <= n; i++) {
		cin >> r[i].first >> r[i].second;
	}
	vector<pii> s;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int x1 = r[i].first;
		int y1 = r[i].second;
		int x2 = r[i + 1].first;
		int y2 = r[i + 1].second;
		
		if (x1 == x2 && y1 == y2) {
			if (x2 == y2 && y2 == 0) {
				res = 1;
			}
			else continue;
		}
		
		int on1 = max(x1, y1);
		int on2 = min(x2, y2);
		
		if (on2 >= on1) s.push_back({on1, on2});
	}
	int l = s.size();
	for (int i = 0; i < l - 1; i++) {
		
	}
	for (auto x : s) cerr << "DEBUG: " << x.first << ' ' << x.second << el;
	for (int i = 0; i < l - 1; i++) {
		res += s[i].second - s[i].first;
	}
	
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
