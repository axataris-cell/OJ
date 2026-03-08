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
	vector<int> b(n + 1, 0);
	map<int, int> mp;

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		++mp[b[i]];
	}
	
	map<int, int> cnt;
	for (int i = 1; i <= n; i++) {
		if (mp[b[i]] % b[i]) {
			cout << -1 << el;
			return;
		}
	}

	int curcnt = -1;
	map<int, int> cor;
	for (int i = 1; i <= n; i++) {
		if (!cnt[b[i]]) {
			cor[b[i]] = ++curcnt;
		}
		if (cnt[b[i]] % b[i] == 0) {
			cor[b[i]] = ++curcnt;
		}
		++cnt[b[i]];
		
		cout << cor[b[i]] << ' ' ;
	}
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
