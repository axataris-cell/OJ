#include <bits/stdc++.h>
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

struct num {
	int v;
	int k, t;
};

void testcase() {
	int n; cin >> n;
	vector<num> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].v;
		a[i].k = i % 2;
		a[i].t = 1 - a[i].k;
	}
	sort(a.begin(), a.end(), [](num x, num y) {
		return x.v < y.v;
	});
	bool check = true;
	for (int i = 0; i < n - 1; i++) {
		if (a[i].k == a[i + 1].k) {
			check = false;
			break;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i].t == a[i + 1].t) {
			check = false;
			break;
		}
	}
	if (check) cout << "YES" << el;
	else cout << "NO" << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
