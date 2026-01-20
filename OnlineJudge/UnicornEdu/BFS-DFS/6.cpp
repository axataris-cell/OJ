#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int MAXN = 2*1e5 + 5;

vector<int> g[MAXN];
vector<int> par(MAXN, -1), cnt(MAXN, 0);
bool vis[MAXN];

void bfs(int s) {
	queue<int> q;
	
	q.push(s);
	vis[s] = true;
	
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (auto u : g[v]) {
			if (!vis[u]) {
				vis[u] = true;
				par[u] = v;
				
				int k = v;
				while (k != -1) {
					++cnt[k]; k = par[k];
				}
				
				q.push(u);
			}
		}
	}
}

void testcase() {
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		g[x].push_back(i);
	}
	
	bfs(1);
	
	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << ' ';	
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
