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
	map<char, int> mp1, mp2;
	for (int i = 3; i <= n; i++) {
		mp2[s[i - 1]]++;
	}
	++mp1[s[0]];
	
	for (int i = 2; i < n; i++) {
		if (i >= 3) --mp2[s[i - 1]];
		if (mp1[s[i - 1]] > 0 || mp2[s[i - 1]] > 0) {
			cout << "YES" << el;
			return;
		}
		++mp1[s[i - 1]];
	}
	cout << "NO" << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
