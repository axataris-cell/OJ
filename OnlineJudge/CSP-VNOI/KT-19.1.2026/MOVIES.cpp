#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME "MOVIES"

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

struct film {
	int s, e;
	int i;
};

struct comp {
	bool operator()(film x, film y) const {
		return x.e > y.e;
	}
};

void testcase() {
	int n; cin >> n;
	vector<film> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].s >> a[i].e;
		a[i].i = i;
	}
	sort(a.begin(), a.end(), [](film x, film y) {
		return x.s < y.s;
	});
	
	vector<int> count(n, 1);
	priority_queue<film, vector<film>, comp> pq;
	for (int i = 0; i < n; i++) {
		if (!pq.empty()) {
			if (a[i].s >= pq.top().e) {
				pq.pop();
				++count[a[i].i];
			}
		}
		pq.push(a[i]);
	}
	int res = *max_element(count.begin(), count.end());
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
