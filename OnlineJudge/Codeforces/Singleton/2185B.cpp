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
void testcase() {
	int n; cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> ord(n + 1, 0);
	iota(ord.begin() + 1, ord.end(), 1);
	sort(ord.begin() + 1, ord.end(), [&](const int &x, const int &y) {
		return a[x] > a[y];
	});
	for (int i = 1; i <= n; i++) {
		if (ord[i] != i) {
			swap(a[ord[i]], a[i]);
			break;
		}
	}
	int mx = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(a[i], mx);
		res += mx;
	}
	
	cout << res << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}
