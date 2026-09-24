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
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
	int n; cin >> n;
	if (n % 4) {
		cout << "NO" << el;
		return;
	}
	cout << "YES" << el;
	int sum = 0;
	for (int i = 1; i <= n / 2; i++) {
		cout << 2*i << ' ';
		sum += 2 * i;
	}
	int s2 = 0;
	for (int i = 1; i <= n / 2 - 1; i++) {
		cout << 2 * i - 1 << ' ';
		s2 += 2 * i - 1;
	}
	cout << sum - s2 << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

