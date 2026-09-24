#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;

vector<int> g[MAXN];
int tin[MAXN], tout[MAXN];

struct Fenwick {
	vector<int> bit;
	int n;
	
	Fenwick(int sz) : bit(sz + 1, 0), n(sz) {
	}
	
	void update(int pos, int val) {
		for (; pos <= n; pos += pos & (-pos)) {
			bit[pos] += val;
		}
	}
	
	int query(int pos) {
		int res = 0;
		for (; pos > 0; pos -= pos & (-pos)) {
			res += bit[pos];
		}
		return res;
	}
};

int timeDfs = 0;

void dfs(int u, int p) {
	tin[u] = ++timeDfs;
	for (int v : g[u]) if (v!= p) {
		dfs(v, u);
	}
	tout[u] = ++timeDfs;
}

void testcase() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);
	
	Fenwick BIT(timeDfs);
	
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int u, val; cin >> u >> val;
			BIT.update(tin[u], val);
			BIT.update(tout[u], -val);
		} else {
			int u; cin >> u;
			cout << BIT.query(tin[u]) << el;
		}
	}
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

