#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

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

vector<int> g[MAXN];
vector<int> num(MAXN, 0), low(MAXN, 0);
bool joint[MAXN];
int timeDfs = 0;

void dfs(int u, int p) {
    int child = 0;
    num[u] = low[u] = ++timeDfs;

    for (int v : g[u]) {
        if (v == p) continue;

        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            ++child;

            if (u == p) {
                if (child > 1) joint[u] = true;
            }
            else {
                if (low[v] >= num[u]) joint[u] = true;
            }
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!num[i]) dfs(i, i);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (joint[i]) ++res;
	}
	
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
