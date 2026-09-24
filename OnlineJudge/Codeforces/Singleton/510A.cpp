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
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 1; j <= m; j++) cout << '#';
			cout << el;
			continue;
		}
		if (i % 4 == 1) {
			for (int j = 1; j < m; j++) cout << '.';
			cout << '#' << el;
		} else {
			cout << '#';
			for (int j = 1; j < m; j++) cout << '.';
			cout << el;
		}
	}
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

