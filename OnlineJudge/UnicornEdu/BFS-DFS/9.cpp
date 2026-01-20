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

struct edge {
	int u, v;
	ll w;
};

void testcase() {
	int n, m, w; cin >> n >> m >> w;
	vector<edge> edges;
	
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back({a, b, c});
		edges.push_back({b, a, c});
	}
	
	for (int i = 0; i < w; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back({a, b, -c});
	}
	
	for (int i = 1; i <= n; i++) edges.push_back({0, i, 0});
	// đồ thị có thể khônng liên thông nên cần một đỉnh 0 có thể đi tới tất cả các đỉnh trong thời gian 0 làm siêu nguồn rồi từ đó bắt đầu bellman fọt từ đỉnh 0.
	
	vector<ll> dist(n + 1, 0);
	bool ncyclic = false;
	
	for (int i = 1; i <= n; i++) {
		bool up = false;
		for (auto e : edges) {
			if (dist[e.v] > dist[e.u] + e.w) {
				dist[e.v] = dist[e.u] + e.w;
				up = true;
				// belman fot chay het n - 1 chu trinh ma neu i = n roi van phat hien duong di tot hon thi bay mau
				if (i == n) {
					ncyclic = true;
					break;
				}
			}
		}
		if (ncyclic) break;
		if (!up) break;
	}
	
	if (ncyclic) cout << "YES" << el;
	else cout << "NO" << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
