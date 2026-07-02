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
bool dis[MAXN];
int mx[MAXN];

void testcase() {
	int n, k, m; cin >> n >> k >> m;
	for (int i = 1; i <= k; i++) {
		int x; cin >> x;
		dis[x] = true;
	}
	vector<int> dp(n + 1, -INT_MAX);
	vector<int> cach(n + 1, -INT_MAX);
	for (int i = 1; i <= m + 1; i++) {
		dp[i] = 1;
		cach[i] = 1;
		mx[i] = 
	}
	for (int i = m + 2; i <= n; i++) {
		
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
