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

int n, m, k, p;

vector<int> g[MAXN];
vector<int> doll;
vector<int> s;
vector<int> f_vis(MAXN, 0);

void testcase() {
	cin >> n >> m >> k >> p;
	for (int i = 1; i <= k; i++) {
		int x; cin >> x;
		doll.push_back(x);
		if (x == 1) {
			cout << "NO";
			return;
		}
	}
	for (int i = 1; i <= p; i++) {
		int x; cin >> x;
		s.push_back(x);
	}
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	queue<pii> q;
	
	for (auto x : doll) {
		q.push({x, x});
		f_vis[x] = x;
	}
	q.push({1, 1});
	f_vis[1] = 1;
	
	while (q.size()) {
		pii x = q.front(); q.pop();
		int u = x.first;
		int t = x.second;
		for (int v : g[u]) {
			if (!f_vis[v]) {
				f_vis[v] = t;
				q.push({v, t});
			}
		}
	}
	
	for (auto x : s) {
		if (f_vis[x] == 1) {
			cout << "YES";
			return;
		}
	} 
	cout << "NO";
	return;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
