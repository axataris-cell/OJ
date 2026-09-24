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
	double n, k; cin >> n >> k;
	
	map<int, bool> vis;
	map<int, int> dist;
	queue<double> q;
	q.push(n);
	vis[n] = true;
	while (q.size()) {
		double u = q.front(); q.pop();
		if (u == k) break;
		int x1 = ceil(u / 2);
		int x2 = floor(u / 2);
		if (!vis[x1]) {
			vis[x1] = true;
			dist[x1] = dist[u] + 1;
			q.push((double)x1);
		}
		if (!vis[x2]) {
			vis[x2] = true;
			dist[x2] = dist[u] + 1;
			q.push((double)x2);
		}
	}
	if (vis[k]) cout << dist[k] << el;
	else cout << -1 << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
