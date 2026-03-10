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
	ll x, y;
};
using Vector = Point;

ll operator % (const Vector &u, const Vector &v) {
	return u.x * v.x + u.y * v.y;
}

ll operator * (const Vector &u, const Vector &v) {
	return u.x * v.y - u.y * v.x;
}

Vector operator + (const Vector &u, const Vector &v) {
	return {u.x + v.x, u.y + v.y};
}

Vector operator - (const Vector &u, const Vector &v) {
	return {u.x - v.x, u.y - v.y};
}

void testcase() {
	int n, m; cin >> n >> m;
	vector<Point> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	a[n] = a[0];
	ll area = 0;
	for (int i = 0; i < n; i++) {
		area += a[i] % a[i + 1];
	}
	area = llabs(area);
	while (m--) {
		Point P; cin >> P.x >> P.y;
		ll total = 0;
		for (int i = 0; i < n; i++) {
			Vector A = a[i] - P;
			Vector B = a[i + 1] - P;
			total += llabs(A % B);
		}
		if (total == area) cout << 'Y' << el;
		else cout << 'N' << el;
	}
}	

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
