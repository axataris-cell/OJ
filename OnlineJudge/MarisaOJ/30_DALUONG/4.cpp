#include <bits/stdc++.h>
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

const int MAXN = 1e5 + 5;

int n, m, k;

vector<int> g[MAXN];
vector<int> r(MAXN, 0);
vector<int> power(MAXN, -1);

void testcase() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	queue<pii> q;
	for (int i = 1; i <= k; i++) {
		int a, d; cin >> a >> d;

		q.push({a, d});
	}
	
	while (q.size()) {
		pii x = q.front(); q.pop();
		int p = x.second;
		int u = x.first;
		
		if (p <= power[u]) continue;
		
		power[u] = p;
		
		for (int v : g[u]) {
			q.push({v, p - 1});
		}
	}
	
	int res = 0;
	
	for (int i = 1; i <= n; i++) {
		if (power[i] != -1) ++res;
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
