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

vector<pii> g[MAXN]; // Adjacent Node - Weight
vector<int> dist(MAXN, INT_MAX);

void dijkstra(int s) {
	pqueue<pii, vector<pii>, greater<pii>> pq; // Min-Heap
	
	dist[s] = 0;
	pq.emplace(0, s);
	
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		
		int d = top.first;
		int u = top.second;
		
		if (d > dist[u]) continue; // Cái này để bỏ trạng thái lỗi thời trong dijkstra, bởi nếu như dist đã được cập nhật bởi một con đường ngắn hơn đi hướng khác thì nếu xét luôn trường hợp dài hơn này thì sẽ chọn một con đường kém hiệu quả hơn trước để đi tới node thứ i từ đó ảnh hưởng tới các con đường khác
		
		for (auto p : g[u]) {
			int v = p.first;
			int w = p.second;
			
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}
}

void testcase() {
	int n, m, s, t; // Vertices, Edges, Start node, Target node
	cin >> n >> m >> s >> t;
	
	for (int i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	
	dijkstra(s);
	
	cout << dist[t];
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
