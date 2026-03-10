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

ll operator * (const Vector &u, const Vector &v) {
	return u.x * v.x + u.y * v.y;
}

ll operator % (const Vector &u, const Vector &v) {
	return u.x * v.y - u.y * v.x;
}

Vector operator + (const Vector &u, const Vector &v) {
	return {u.x + v.x, u.y + v.y};
}

Vector operator - (const Vector &u, const Vector &v) {
	return {u.x - v.x, u.y - v.y};
}

void testcase() {
	int n; cin >> n;
	vector<Point> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	a[n] = a[0];
	
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i] % a[i + 1];
	}
	res = llabs(res);
	if (res % 2) {
		cout << res / 2 << ".5";
	} else cout << res / 2 << ".0";
}	

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
