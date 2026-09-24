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
struct Trie {
	int nodecnt;
	struct Node {
		int nxt[11];
		int cnt;
		Node() {
			cnt = 0;
			for (int i = 0; i < 11; i++) nxt[i] = 0;
		}
	};
	vector<Node> pool;
	Trie(int n, int m) : pool(n * m + 1, Node()), nodecnt(0) {
	}
	
	void add(vector<int> &a) {
		int cur = 0;
		int n = a.size();
		for (int i = 0; i < n; i++) {
			if (pool[cur].nxt[a[i]] == 0) {
				pool[cur].nxt[a[i]] = ++nodecnt;
			}
			cur = pool[cur].nxt[a[i]];
			++pool[cur].cnt;
		}
	}
	
	int solve(vector<int> &a) {
		int cur = 0;
		int res = 0;
		int n = a.size();
		for (int i = 0; i < n;i++) {
			if (pool[cur].nxt[a[i]] == 0) {
				break;
			}
			res = i + 1;
			cur = pool[cur].nxt[a[i]];
		}
		return res;
	}
};
void testcase() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	Trie trie(n, m);
	for (int i = 0; i < n; i++) {
		trie.add(a[i]);
	}
	for (int i = 0; i < n; i++) {
	    vector<int> p(m);
	    for (int j = 0; j < m; j++) {
	        p[a[i][j] - 1] = j + 1;
	    }
	    cout << trie.solve(p) << ' ';
	}
	cout << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

