#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME "GTD"

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

const int MAXN = 2e5 + 5;

vector<int> a(MAXN, 0);

void testcase() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (q--) {
		int l, r; cin >> l >> r;
		ll total = 0;
		map<int, int> mp;
		for (int i = l; i <= r; i++) {
			++mp[a[i]];
		}
		for (auto x : mp) {
			total += x.second * x.second * x.first * 1LL;
		}
		cout << total << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
