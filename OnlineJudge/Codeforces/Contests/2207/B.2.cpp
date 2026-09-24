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

/*
1
1 2 10
10
*/

//after x amount of lights, we js need to increase the other m - x monster

void testcase() {
	int n, m, l; cin >> n >> m >> l;
	vector<int> light(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> light[i];
	}
	
	int mx = 0;
	int cnt = 0;
	int res = 0;
	int fill = 0;
	for (int i = 1; i <= n; i++) {
		int time = light[i] - light[i - 1] - 1;
		int mod = time % (m - cnt);
		int gain = time / (m - cnt);
		cerr << "DEBUG: " << i << ' ' << "VAL " << time << ' ' << mod << ' ' << gain << el; 
		res = max(res, mx + time);
		mx += gain;
		if (mod) ++mx;
		if (mod + fill == m - cnt) {
			++mx;
			mod = 0;
			fill = 0;
		}
		fill = ((m - cnt) - mod) % (m - cnt);
		if (mod == 1) {
			--fill;
			--mx;
		}
		res = max(res, mx);
		cerr << res << ' ' << fill << ' ' << mx << el;
		++cnt;
		if (cnt == m) {
			cnt = 0;
			mx = 0;
			fill = 0;
		}
//		cerr << mx << ' ' << cnt << ' ' << res << ' ' << fill << el;
	}
	res = max(res, mx + l - light[n]);
	
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
