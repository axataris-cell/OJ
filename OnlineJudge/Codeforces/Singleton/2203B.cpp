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
	string s; cin >> s;
	int n = s.length();
	
	map<int, int> mp;
	
	int S = 0;
	for (int i = n - 1; i >= 0; i--) {
		S += s[i] - '0';
		if (i != 0) mp[s[i] - '0']++;
	}
	int first = s[0] - '0';
	
	int res = 0;
	
	for (int i = 9; i >= 0; i--) {
		if (i == first - 1 && S >= 10) {
			++res;
			S -= first - 1;
		}
		while (S >= 10 && mp[i] > 0) {
			++res;
			S -= i;
			mp[i]--;
		}
		if (S < 10) break;
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
