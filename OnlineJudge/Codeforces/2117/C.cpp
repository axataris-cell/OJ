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

void testcase() {
	int n; cin >> n;
	vector<int> a(n + 1, 0);
	vector<int> prev(n + 1, -1);
	vector<int> next(n + 1, -1);
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		++mp[a[i]];
		if (prev[a[i]] == -1) {
			prev[a[i]] = i;
		} else {
			next[prev[a[i]]] = i;
			prev[a[i]] = i;
		}
	}
//	
//	for (int i = 1; i <= n; i++) {
//		cerr << next[i] << ' ';
//	}
//	cerr << el;
	
	int res = 1;
	int tar = 1, nxt = 1;
	for (int i = 1; i <= n; i++) {
		--mp[a[i]];
		if (!mp[a[i]]) {
			break;
		}
		nxt = max(nxt, next[i]);
		if (i == tar) {
			++res;
			tar = nxt;
		}
//		cerr << i << ' ' << res << ' ' << tar << ' ' << nxt << el;
	}
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
