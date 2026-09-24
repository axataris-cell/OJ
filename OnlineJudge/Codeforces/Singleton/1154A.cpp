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
	int x[4];
	for (int i = 0; i < 4; i++) cin >> x[i];
	int idx = -1;
	int mx = 0;
	for (int i = 0; i < 4; i++) {
		if (x[i] > mx) {
			mx = x[i];
			idx = i;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (i == idx) continue;
		cout << mx - x[i] << ' ';
	}
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

