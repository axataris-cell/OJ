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
const int INF=2e9,MAXN=1e6+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
bool p[MAXN];
void testcase() {
	for (int i = 2; i < MAXN; i++) p[i] = true;
	for (int i = 2; i * i < MAXN; i++) {
		if (p[i]) {
			for (int j = i * i; j < MAXN; j += i) p[j] = false;
		}
	}
	
	int n; cin >> n;
	for (int i = 2; i < n; i++) {
		if (p[i]) continue;
		int other = n - i;
		if (other != 1 && !p[other]) {
			cout << i << ' ' << other;
			return;
		}
	}
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

