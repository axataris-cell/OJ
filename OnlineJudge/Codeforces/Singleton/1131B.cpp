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
	pqueue<pii, vector<pii>, greater<pii>> pq;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int x1 = r[i].first;
		int y1 = r[i].second;
		int x2 = r[i + 1].first;
		int y2 = r[i + 1].second;
		
		int on1 = max(x1, y1);
		int on2 = min(x2, y2);
		
		if (on2 >= on1) {
			pq.emplace(on1, on2);
		}
	}
	while (pq.size()) {
		pii u = pq.top(); pq.pop();
		if (pq.size() && pq.top().first == u.second) {
			int newa = pq.top().second;
			pq.pop();
			pq.emplace(u.first, newa);
		} else {
			res += u.second - u.first + 1;
		}
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
