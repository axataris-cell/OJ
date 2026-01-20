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
	int n; cin >> n;

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		++mp[x];
	}
	int cnt = 0;
	int mex = 0;
	for (int i = 0; i <= n; i++) {
		if (mp[i] == 0) {
			mex = i;
			break;
		}
	}
	for (int i = mex - 1; i <= n; i++) {
		++cnt;
	}
	
	if (mp[0] == 0) cout << "NO" << el;
	else {
		if ((cnt && mp[0] == 1) || mex > 1) cout << "YES" << el;
		else cout << "NO" << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
