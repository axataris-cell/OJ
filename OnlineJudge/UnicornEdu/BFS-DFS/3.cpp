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
const int MAXN = 3*1e4 + 5;

vector<int> par(MAXN, -1), dis(MAXN, 0);
bool visited[MAXN];
vector<int> g[MAXN];

void bfs(int s) {
	queue<int> q;
	
	q.push(s);
	visited[s] = true;
	
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		
		for (auto v : g[x]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = true;
				dis[v] = dis[x] + 1;
				par[v] = x;
			}
		}
	}
}

void testcase() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++) {
		int a; cin >> a;
		g[i].push_back(i + a);
	}
	
	bfs(1);
	
	if (visited[k]) cout << "YES";
	else cout << "NO";
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
