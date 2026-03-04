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

int n;
string in;
vector<int> mp(10, 0);

bool valid(int s) {
	while (s > 0) {
		int m = s % 10;
		if (mp[m]) return false;
		s /= 10;
	}
	return true;
}

void testcase() {
	cin >> n;
	cin >> in;
	for (int i = 0; i < (int)in.length(); i++) {
		++mp[in[i] - '0'];
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (valid(i)) ++res;
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
