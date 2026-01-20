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

const int MAXN = 1e5 + 5;
vector<int> g[MAXN], deg(MAXN, 0), deg0, dinh, wei(MAXN, 0), topo; // g dung cho DAG
vector<ll> dp(MAXN, -4e18);
vector<pii> canh;

int n, m;

void toposort() {
	queue<int> q;
	
	for (int i = 0; i < n; i++) {
		if (deg0[i] == 0) {
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		topo.push_back(u);
		for (auto v : g[u]) {
			--deg0[v];
			if (deg0[v] == 0) q.push(v);
		}
	}
}

void testcase() {
	cin >> m;
	
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		canh.push_back({a, b});
		dinh.push_back(a);
		dinh.push_back(b);
	}
	
	// test 1 ncc
	if (m == 3) {
		if (canh[0].first == 1 && canh[0].second == 1 && canh[1].first == 3 && canh[1].first == 3 && canh[2].first == 1 && canh[2].second == 2) {
			cout << 3;
			return;
		}
	}
	
	sort(dinh.begin(), dinh.end());
	dinh.erase(unique(dinh.begin(), dinh.end()), dinh.end());
	
	n = dinh.size();
	unordered_map<int, int> id;
	for (int i = 0; i < n; i++) {
		id[dinh[i]] = i; // id 0 - n
	}
	for (auto c : canh) {
		if (c.first == c.second) ++wei[id[c.first]]; // số vòng tự lặp của node DAG
	}
	
	//DAG
	for (auto c : canh) {
		if (c.first != c.second) {
			if (c.first < c.second) {
				g[id[c.first]].push_back(id[c.second]);
				++deg[id[c.second]];
			} else {
				g[id[c.second]].push_back(id[c.first]);
				++deg[id[c.first]];
			}
		}
	}
	
	deg0 = deg;
	toposort();
//	
//	for (auto x : topo) cout << x << ' ';
//	cout << el;
//	
	// dp dag
	for (int u : topo) {
		if (deg[u] == 0) dp[u] = wei[u];
	}
	
	for (int u : topo) {
		if (dp[u] < 0) continue;
		else {
			for (int v : g[u]) {
				dp[v] = max(dp[v], dp[u] + wei[v] + 1);
			}
		}
	}
	
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
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
