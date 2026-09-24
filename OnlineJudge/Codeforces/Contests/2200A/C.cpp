#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

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

	while (s.size() > 1) {
		bool changed = false;
		for (int i = 1; i < s.size(); i++) {
			while (i < s.size() && s[i] == s[i - 1]) {
				changed = true;
				s.erase(i - 1, 2);
			}
		}
		if (!changed) break;
	}
	
	if (s.size()) cout << "NO" << el;
	else cout << "YES" << el;
}

/*
1
12
siixxsevvenn
*/

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
