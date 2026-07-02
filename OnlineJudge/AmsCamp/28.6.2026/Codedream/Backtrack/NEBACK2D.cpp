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

int n, k;

void backtrack(string s, int len, int cnt) {
	if (n - len < k - cnt) return;
	if (len == n) {
		if (cnt < k) return;
		for (auto x : s) cout << x << ' ';
		cout << el;
		return;
	}
	backtrack(s + "0", len + 1, cnt);
	backtrack(s + "1", len + 1, cnt + 1);
}

void testcase() {
	cin >> n >> k;
	backtrack("", 0, 0);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
