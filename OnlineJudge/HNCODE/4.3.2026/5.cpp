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

#define int long long

const int MAXN = 505;

int n, m;

bool vis[MAXN];
vector<int> a(MAXN), b(MAXN), c(MAXN);
int res = 0;

void dfs(int idx, int ttc, int value, int k) {
	if (k == n) {
		res = max(res, value);
		return;
	}
	vis[idx] = true;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		if (ttc + c[i] > m) continue;
		
		dfs(i, ttc + c[i], value + a[i] - b[i] * (k + 1), k + 1);
	}
	vis[idx] = false;
	res = max(res, value);
}
/*
5 10
8 2 3
7 1 4
10 5 5
6 1 1
9 3 2
*/

void testcase() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, c[i], a[i], 0);
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
