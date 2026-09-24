#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 1e9
#define LINF 1e18

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
	int a, b, c; cin >> a >> b >> c;
	vector<int> all;
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 5; j++) {
			for (int k = 0; k <= 5; k++) {
				if (i + j + k == 5) {
					all.push_back((a + i) * (b + j) * (c + k));
				}
			}
		}
	}
	sort(all.begin(), all.end(), greater<int>());
	
	cout << all[0];
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
