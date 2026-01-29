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

int n;
vector<int> res;

bool dfs(int s, int cnt, vector<bool> &vis) {
	if (vis[s]) return false;
	if (s > n || s <= 0) {
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) ++count;
		}
		if (count == n) {
			return true;
		}
		return false;
	}
	vis[s] = true;
	bool k = dfs(s - cnt, cnt + 1, vis);
	if (k) {
		res.push_back(s);
		return true;
	}
	k = dfs(s + cnt, cnt + 1, vis);
	if (k) {
		res.push_back(s);
		return true;
	}
	return false;
}

void testcase() {
	res.clear();
	cin >> n;
	vector<bool> vis(n + 1, false);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) vis[j] = false;
		bool ok = dfs(i, 1, vis);
		if (ok) break;
	}
	reverse(res.begin(), res.end());
	for (auto x : res) cout << x << ' ';
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
