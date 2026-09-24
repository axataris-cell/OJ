#include <bits/stdc++.h>
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

const int MAXN = 1e3 + 5;

char g[MAXN][MAXN];
int res = -1;

void bfs(int s) {
	
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
		}
	}
	bool check = false;
	for (int i = 1; i <= n; i++) {
		if (g[i][1] == '#') {
			check = true;
			break;
		}
	}
	if (!check) {
		cout << res; return;
	}
	check = false;
	for (int i = 1; i <= m; i++) {
		if (g[1][i] == '#') {
			check = true;
			break;
		}
	}
	if (!check) {
		cout << res; return;
	}
	
	bfs(1);
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
