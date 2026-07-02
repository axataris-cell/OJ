#include <bits/stdc++.h>
#include <chrono>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME "PDX"

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

void debug_time(const string& label = "") {
    static auto start = chrono::steady_clock::now();
    auto now = chrono::steady_clock::now();
    double ms = chrono::duration<double, milli>(now - start).count();
    cerr << "[TIME] " << label << ": " << ms << " ms\n";
}

const int MAXN = 1e9 + 5;

struct segment {
	int l, r;
	int value;
};

struct comp {
	bool operator()(segment a, segment b) const {
		return a.r < b.l;
	}
};
pqueue<segment, vector<segment>, comp> segments;

void testcase() {
	int n, m; cin >> n >> m;
	while (m--) {
		int l, r; cin >> l >> r;
		if (l <= r) segments.push({l, r, 1});
		else {
			segments.push({l, n, 1});
			segments.push({1, r, 1});
		}
	}
	while (!segments.empty()) {
		segment x = segments.top(); segments.pop();
		cout << x.l << ' ' << x.r << ' ' << x.value << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	debug_time();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
