#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME "TDL"

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

vector<int> g[MAXN];
vector<int> dist(MAXN, 0);
bool vis[MAXN];

void testcase() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = false;
        dist[i] = -1;
    }

    for (int i = 1; i <= n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int m; cin >> m;
    queue<int> q;

    for (int i = 0; i < m; i++) {
        int s; cin >> s;
        q.push(s);
        vis[s] = true;
        dist[s] = 0;
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dist[i]);
    }

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
