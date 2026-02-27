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

int count(int n) {
	string s = to_string(n);
	int cnt = 0;
	for (int i = 0; i < s.length(); i += 2) {
		if (s[i] == '0') ++cnt;
	}
	return cnt;
}

void testcase() {
	int a, b; cin >> a >> b;
	int res = 0;
	for (int i = a; i <= b; i++) {
		res += count(i);
	}
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
