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

struct segment {
	ll r, a, b;
};

ll xs, ys ,xe, ye;
int n;

vector<segment> segs;
umap<ll, vector<int>> hang;

int search(ll x, ll y) {
	for (int i = 0; i < n; i++) {
		if (segs[i].r == x && segs[i].a <= y && y <= segs[i].b) {
			return i;
		}
	}
	return -1;
}

bool valid(segment u, segment v) {
	if (llabs(u.r - v.r) > 1) return false;
	if (max(u.a, v.a) > min(u.b, v.b) + 1) return false;
	return true;
}

int bfs(int start, int end) {
	vector<int> dist(n, -1);
	queue<int> q;
	
	dist[start] = 0;
	q.push(start);
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == end) return dist[u];
		
		segment cur = segs[u];
		
		for (ll nr = cur.r - 1; nr <= cur.r + 1; nr++) {
			if (!hang.count(nr)) continue;
			
			for (int v : hang[nr]) {
				if (dist[v] != -1) continue;
				if (!valid(cur, segs[v])) continue;
				if (segs[v].a > cur.b + 1) break;
				
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return -1;
}

void testcase() {
	cin >> xs >> ys >> xe >> ye;
	cin >> n;
	
	segs.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> segs[i].r >> segs[i].a >> segs[i].b;
	}
	
	hang.reserve(2 * n);
	
	for (int i = 0; i < n; i++) {
		hang[segs[i].r].push_back(i);
	}
	
	for (auto &p : hang) {
		auto &v = p.second;
		sort(v.begin(), v.end(), [&](int i, int j) {
			return segs[i].a < segs[j].a;
		});
	}
	
	int start = search(xs, ys);
	int end = search(xe, ye);
	
	if (start == -1 || end == -1) {
		cout << -1; return;
	}
	
	cout << bfs(start, end);
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
