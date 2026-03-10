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

using Coord = long long;
struct Point {
	Coord x, y;
};
using Vector = Point;

Coord operator % (const Vector &u, const Vector &v) { // Tích chấm
	return u.x * v.x + u.y * v.y;
}

Coord operator * (const Vector &u, const Vector &v) { // Tích chéo
	return u.x * v.y - u.y * v.x;
}

Vector operator + (const Vector &u, const Vector &v) {
	return {u.x + v.x, u.y + v.y};
}

Vector operator - (const Vector &u, const Vector &v) {
	return {u.x - v.x, u.y - v.y};
}

void testcase() {
	
}	

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
