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
	vector<int> f(n + 1, 0), a(n + 1, 0), s(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = max(f[i - 1], a[i]);
	}
	for (int i = n; i >= 1; i--) {
		s[i] = (i == n ? a[i] : max(s[i + 1], a[i]));
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] - max(f[i - 1], s[i + 1]) << ' ';
	}
	cout << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


