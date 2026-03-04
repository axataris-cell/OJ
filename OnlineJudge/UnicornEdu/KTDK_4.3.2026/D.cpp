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

vector<int> xaihi;

void preprocess(int k, int prev, int cur) {
	if (k > 9) return;
	xaihi.push_back(cur);
	for (int i = prev + 1; i <= 9; i++) {
		preprocess(k + 1, i, cur * 10 + i);
	}
}

void testcase() {
	int a; cin >> a;
	auto it = upper_bound(xaihi.begin(), xaihi.end(), a) - 1 - xaihi.begin();
	cout << xaihi[it] << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();
	
	xaihi.push_back(0);
	for (int i = 1; i <= 9; i++) {
		preprocess(1, i, i);
	}
	sort(xaihi.begin(), xaihi.end());

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
