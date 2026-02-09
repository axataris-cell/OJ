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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int res = 0;

bool vis[9][9];
bool block[9][9];

bool valid(pii u) {
	int x = u.first, y = u.second;
	return x >= 1 && x <= 8 && y >= 1 && y <= 8 && !block[x][y];
}

void dq(pii s, int dist, int k) {
	vis[s.first][s.second] = true;
	res = max(res, dist);
	pii ns = {s.first + dx[k], s.second + dy[k]};
	if (valid(ns)) {
		if (vis[ns.first][ns.second]) {
			vis[s.first][s.second] = false;
			return;
		}
		dq(ns, dist + 1, k);
	} else {
		pii ns1 = {s.first + dx[((k + 1) + 4) % 4], s.second + dy[((k + 1) + 4) % 4]};
		pii ns2 = {s.first + dx[((k - 1) + 4) % 4], s.second + dy[((k - 1) + 4) % 4]};
		if (valid(ns1) && !vis[ns1.first][ns1.second]) {
			dq(ns1, dist + 1, ((k + 1) + 4) % 4);
		} 
		if (valid(ns2) && !vis[ns2.first][ns2.second]) {
			dq(ns2, dist + 1, ((k - 1) + 4) % 4);
		}
	}
	vis[s.first][s.second] = false;
	return;
}
void testcase() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		char a; cin >> a;
		int b; cin >> b;
		block[b][a - 'A' + 1] = true;
	}
	dq({1, 1}, 1, 2);
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
