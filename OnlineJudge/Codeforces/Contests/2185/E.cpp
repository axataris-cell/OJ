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

void testcase() {
	int n, m, k; cin >> n >> m >> k;
	vector<pii> line;
	int move = 0;
	
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		line.push_back({x, 0});
	}
	for (int i = 1; i <= m; i++) {
		int x; cin >> x;
		line.push_back({x, 1});
	}
	sort(line.begin(), line.end());
	
	string s; cin >> s;
	for (auto x : s) {
		if (x == 'L') --move;
		else ++move;
	}
	
	vector<pii> dist;
	
	for (auto p : line) {
		if (p.second == 0) {
			pii res = {0, 0};
			int i = p.first;
			while (i > 0) {
				if (line[i].second == 1)  {
					res.first = i - p.first;
					break;
				}
				--i;
			}
			i = p.first;
			while (i < n + m) {
				if (line[i].second == 1) {
					res.second = i - p.first;
					break;
				}
				++i;
			}
			dist.push_back(res);
		}
	}
	
	int res = 0;
	for (auto p : dist) {
		if (p.first != 0 && p.first >= move) {
			++res; continue;
		}
		if (p.second != 0 && p.second <= move) {
			++res; continue;
		}
	}
	
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
