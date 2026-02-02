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

struct num {
	int val, tin;
	int idx;
};

struct comp {
	bool operator()(const num &x, const num &y) const {
		return x.val > y.val;
	}
};

void testcase() {
	int n, m; cin >> n >> m;
	
	vector<int> a(n);
	pqueue<num, vector<num>, comp> pq; // v - tin
	vector<int> tin(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 0) {
			pq.push({a[i], 0, i});
		}
	}
	
	int clok = 1;
	while (m--) {
		char thaotac; cin >> thaotac;
		if (thaotac == 'S') {
			int x, k; cin >> x >> k; --x;
			if (k > 0) pq.push({k, clok, x});
			tin[x] = clok++;
			a[x] = k;
		} else {
			while (pq.size()) {
				if (pq.top().tin < tin[pq.top().idx]) {
					pq.pop();
				} else break;
			}
			if (!pq.size()) {
				cout << 0 << el;
				continue;
			} else cout << pq.top().val << el;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
