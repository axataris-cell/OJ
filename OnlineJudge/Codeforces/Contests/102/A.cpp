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

#define INF 2e9

const int MAXN = 1e2 + 5;

bool adj[MAXN][MAXN];
vector<int> v(MAXN, 0);

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		adj[a][b] = true;
		adj[b][a] = true;
	}
	int res = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			for (int k = 1; k < j; k++) {
				if (adj[i][j] && adj[i][k] && adj[j][k]) {
					res = min(res, v[i] + v[j] + v[k]);
				}
			}
		}
	}
	
	if (res == INF) {
		cout << -1 << el;
	} else {
		cout << res;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
