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
	string s; cin >> s;
	
	string t = s;
	for (int i = 1; i < n - 1; i++) {
		if (t[i - 1] == t[i + 1] && t[i - 1] == '1') {
			t[i] = '1';
		}
	}
	
	string g = t;
	for (int i = 1; i < n - 1; i++) {
		if (g[i - 1] == g[i + 1] && g[i - 1] == '1') {
			g[i] = '0';
		}
	}
	
	int res = 0;
	int res2 = 0;
	for (int i = 0; i < n; i++) {
		if (t[i] == '1') ++res;
		if (g[i] == '1') ++res2;
	}
	
	cout << res2 << ' ' << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
