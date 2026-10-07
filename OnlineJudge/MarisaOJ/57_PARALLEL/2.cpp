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

int n, q;

vector<int> ST(2 * MAXN, 0);
int a[MAXN];
int ans[MAXN];

struct Update {
	int l, r, w;	
} updates[MAXN];

void update(int l, int r, int val) {
	for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ST[l++] += val;
		if (r & 1) ST[--r] += val;
	}
}
	
int query(int pos) {
	int res = 0;
	for (pos += n - 1; pos > 0; pos >>= 1) {
		res += ST[pos];
	}
	return res;
}

inline bool check(int idx) {
	return a[idx] <= query(idx);
}

void prlbs(int l, int r, vector<int> queries) {
	if (queries.empty()) return;
	
	int mid = (l + r) / 2;
	
	for (int i = l; i <= mid; i++) {
		update(updates[i].l, updates[i].r, updates[i].w);
	}
	
	if (l == r) {
		for (auto id : queries) {
			if (check(id)) ans[id] = l;
			else ans[id] = -1;
		}
		
		for (int i = l; i <= mid; i++) {
            update(updates[i].l, updates[i].r, -updates[i].w);
        }
		return;
	}
	
	vector<int> lq, rq;
	for (auto id : queries) {
		if (check(id)) lq.push_back(id);
		else rq.push_back(id);
	}
	
	for (int i = l; i <= mid; i++) {
		update(updates[i].l, updates[i].r, -updates[i].w);
	}
	
	prlbs(l, mid, lq);
	
	for (int i = l; i <= mid; i++) {
        update(updates[i].l, updates[i].r, updates[i].w);
    }

	prlbs(mid + 1, r, rq);
	
	for (int i = l; i <= mid; i++) {
		update(updates[i].l, updates[i].r, -updates[i].w);
	}
}

void testcase() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> updates[i].l >> updates[i].r >> updates[i].w;
	}
	
	vector<int> qry(n);
	iota(qry.begin(), qry.end(), 1);
	
	prlbs(1, q, qry);
	
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}


