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

int cntnode = 0;
vector<int> roots;

int update(int cur, int l, int r, int pos, int val) {
	int nnode = ++cntnode;
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

int walk(int k, int l, int r, int rl, int rr) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	int left = dow[dow[rr].l].sum - dow[dow[rl].l].sum;
	if (left >= k) return walk(k, l, mid, dow[rl].l, dow[rr].l);
	else return walk(k - left, mid + 1, r, dow[rl].r, dow[rr].r);
}

void testcase() {
	int n, q; cin >> n >> q;
	
	vector<int> a(n + 1, 0);
	roots.reserve(n + 1), roots.push_back(0);
	vector<int> comp;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		comp.push_back(a[i]);
	}
	
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	auto get_id = [&](int val) -> int {
		return lower_bound(comp.begin(), comp.end(), val) - comp.begin() + 1;
	};
	int m = comp.size();
	
	// build PST
	for (int i = 1; i <= n; i++) {
		int v = get_id(a[i]);
		roots.push_back(update(roots[i - 1], 1, m, v, 1));
	}
	
	while (q--) {
		int l, r, k; cin >> l >> r >> k;
		cout << comp[walk(k, 1, m, roots[l - 1], roots[r]) - 1] << el;
	}
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}


