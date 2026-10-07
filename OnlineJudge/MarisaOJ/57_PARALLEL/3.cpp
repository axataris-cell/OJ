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
const int INF=4e18,MAXN=1e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;

struct Node {
	int sum, l, r;
} dow[LOG * MAXN];

int nodecnt;
vector<int> roots;

int update(int cur, int l, int r, int pos, int val) {
	int nnode = ++nodecnt;
	dow[nnode] = dow[cur];
	if (l == r) {
		dow[nnode].sum += val;
		return nnode;
	}
	
	int mid = (l + r) / 2;
	
	if (pos <= mid) dow[nnode].l = update(dow[nnode].l, l, mid, pos, val);
	else dow[nnode].r = update(dow[nnode].r, mid + 1, r, pos, val);
	
	dow[nnode].sum = dow[dow[nnode].l].sum + dow[dow[nnode].r].sum;
	
	return nnode;
}

int query(int cur, int l, int r, int ql, int qr) {
	if (!cur || l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) return dow[cur].sum;
	int mid = (l + r) / 2;
	return query(dow[cur].l, l, mid, ql, qr) + query(dow[cur].r, mid + 1, r, ql, qr);
}

void testcase() {
	int n, q; cin >> n >> q;
	
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	// build PST
	
	roots.push_back(0);
	for (int i = 1; i <= n; i++) {
		roots.push_back(update(roots[i - 1], 1, MAXN, a[i], 1));
	}
	
	// queries
	
	auto check = [&](int l, int r, int vl, int vr, int a) -> bool {
		return query(roots[r], 1, MAXN, vl, vr) - query(roots[l - 1], 1, MAXN, vl, vr) >= a;
	};
	
	while (q--) {
		int l, r, x, a; cin >> l >> r >> x >> a;
		
		int res = -1;
		int L = x, R = n;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (check(x, mid, l, r, a)) {
				res = mid;
				R = mid - 1;
			} else L = mid + 1;
		}
		
		cout << res << ' ';
	}
}

int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}


