#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

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
	ll a, b; cin >> a >> b;
	ll res = 0;
	if (b % 4) {
		if (b % 2) {
			if (a % 2) res = a * b + 1;
			else {
				cout << -1 << el;
				return;
			}
		} else {
			if (a % 2) {
				cout << -1 << el;
				return;
			} else res = a * b / 2 + 2;
		}
	} else {
		res = a * b / 2 + 2;
	}
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
