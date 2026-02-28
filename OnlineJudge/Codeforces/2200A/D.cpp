#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

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
5 1 3
1 3 5 2 4
*/

void testcase() {
	int n, x, y; cin >> n >> x >> y;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int mn = INF;
	int pos = -1;
	for (int i = x + 1; i <= y; i++) {
		if (a[i] < mn) {
			mn = a[i];
			pos = i;
		}
	}
	vector<int> left, mid, right;
	for (int i = x + 1; i <= y; i++) {
		mid.push_back(a[pos]);
		++pos;
		if (pos > y) pos = x + 1;
	}
	int piss = INF;
	for (int i = 1; i <= n; i++) {
		if (i >= x + 1 && i <= y) continue;
		piss = i;
		if (a[i] < mn) {
			left.push_back(a[i]);
		} else break;
	}
	for (int i = piss; i <= n; i++) {
		if (left.size() + mid.size() + right.size() >= n) break;
		if (i >= x + 1 && i <= y) continue;
		right.push_back(a[i]);
	}
	for (auto x : left) cout << x << ' ';
	for (auto x : mid) cout << x << ' ';
	for (auto x : right) cout << x << ' ';
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
