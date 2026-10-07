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
const int INF=2e9,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;

struct Node {
	int sum, l, r;
} dow[MAXN * LOG];

vector<int> roots;
int cntnode = 0;

int update(int curnode, int l, int r, int pos, int val) {
	int nn = ++cntnode;
	dow[nn] = dow[curnode];
	if (l == r) {
		dow[nn].sum = val;
		return nn;
	}	
	int mid = (l + r) / 2;
	if (pos <= mid) dow[nn].l = update(dow[nn].l, l, mid, pos, val);
	else dow[nn].r = update(dow[nn].r, mid + 1, r, pos, val);
	dow[nn].sum = dow[dow[nn].l].sum + dow[dow[nn].r].sum;
	
	return nn;
}

int query(int curnode, int l, int r, int ql, int qr) {
	if (!curnode || l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) return dow[curnode].sum;
	int mid = (l + r) / 2;
	return query(dow[curnode].l, l, mid, ql, qr) + query(dow[curnode].r, mid + 1, r, ql, qr);
}

void testcase() {
	
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


