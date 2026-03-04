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

string a;
int res = 0;

bool valid(string s) {
	for (int i = 1; i < s.length(); i++) {
		if (s[i] <= s[i - 1]) return false;
	}
	return true;
}

void testcase() {
	cin >> a;
	int l = 0, r = stoi(a);
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (valid(to_string(mid))) {
			res = max(res, mid);
			l = mid + 1;
		}
	}
}
	
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
