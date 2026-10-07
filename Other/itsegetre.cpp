#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;

struct Segtree {
	vector<int> ST;
	int n;
	
	Segtree(int sz) : n(sz), ST(2 * sz, 0) {}
	
	void build(vector<int> &a) {
		for (int i = n; i < 2 * n; i++) {
			ST[i] = a[i - n + 1];
		}
		for (int i = n - 1; i > 0; i--) {
			ST[i] = ST[i << 1] + ST[i << 1 | 1];
		}
	} 	
	
	void update(int pos, int val) {
		pos += n - 1;
		ST[pos] = val;
		for (; (pos >> 1) > 0; pos >>= 1) {
			ST[pos >> 1] = ST[pos] + ST[pos ^ 1];
		}
	}
	
	int query(int l, int r) {
		int res = 0;
		l += n - 1;
		r += n;
		while (l < r) {
			if (l & 1) {
				res += ST[l++];
			}
			if (r & 1) {
				res += ST[--r];
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}
};

void testcase() {
	int n; cin >> n;
	int q; cin >> q;
	
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	Segtree ST(n);
	ST.build(a);
	
	while (q--) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) ST.update(a, b);
		else cout << ST.query(a, b) << el;
	}
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}


