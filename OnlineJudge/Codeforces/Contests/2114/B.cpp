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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	
	if (n / 2 < k) {
		cout << "NO" << el;
		return;
	}
	
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') ++cnt0;
		else ++cnt1;
	}
	
	while (k > 0 && cnt1 >= 0 && cnt0 >= 0) {
		if (cnt1 > cnt0) cnt1 -= 2;
		else cnt0 -= 2;
		--k;
	}
	
	if (k > 0 || cnt1 != cnt0 || cnt1 < 0 || cnt0 < 0) {
		cout << "NO" << el;
	} else cout << "YES" << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
