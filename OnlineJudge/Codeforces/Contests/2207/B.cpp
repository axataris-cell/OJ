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

/*
1
2 3 40
13 37
*/

//after x amount of lights, we js need to increase the other m - x monster

void testcase() {
	int n, m, l; cin >> n >> m >> l;
	vector<bool> light(l + 1, 0);
	vector<int> a(m + 1, 0);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		light[x] = 1;
	}
	int lastlight = -1;

	vector<int> prefmx(l + 1, -INF);
	for (int i = 1; i <= l; i++) {
		
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
