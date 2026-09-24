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

struct Point {
	int x, y;
};

void testcase() {
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	Point s, t;
	cin >> s.x >> s.y >> t.x >> t.y;
	vector<Point> points(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> points[i].x;
	}
	for (int i = 1; i <= n; i++) {
		cin >> points[i].y;
	}
	
	sort(points.begin() + 1, points.begin() + n + 1, [](Point x, Point y) {
		return x.x < y.x;
	});
	
	// dist = |xi - xj| + |yi - yj|
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
