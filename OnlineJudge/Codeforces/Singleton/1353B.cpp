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
void testcase() {
	int n, k; cin >> n >> k;
	vector<int> a(n + 1, 0), b(n + 1, 0);
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	sort(a.begin() + 1, a.end());
	
	pqueue<int, vector<int>> pq;
	int s = 0;
	
	for (int i = 1; i <= n; i++) {
		pq.push(b[i]);
		s += a[i];
	}
	
	int ptr = 1;
	
	while (k > 0 && pq.size()) {
		auto u = pq.top(); pq.pop();
		if (u > a[ptr]) {
			s -= a[ptr];
			s += u;
			++ptr;
			--k;
		}
	}
	
	cout << s << el;
	

}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

