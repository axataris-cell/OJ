#include <bits/stdc++.h>
#include <chrono>
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

const int MAXN = 1e7 + 5;

int pref[3][MAXN]; //L Q D

void testcase() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	for (int i = 1; i <= n; i++) {
		for (int c = 0; c < 2; c++) pref[c][i] = pref[c][i - 1];
		if (s[i - 1] == 'L') ++pref[0][i];
		if (s[i - 1] == 'Q') ++pref[1][i];
		if (s[i - 1] == 'D') ++pref[2][i];
	}
	int res = 0;
	for (int c = 0; c < 2; c++) {
		auto x = binary_search(pref[c], pref[c] + n + 1, k);
		res += pref[c][n] - pref[c][x];
	}
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
