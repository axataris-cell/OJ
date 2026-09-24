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
	int n; cin >> n;
	int res = 0;
	map<string, int> st;
	st["Tetrahedron"] = 4;
	st["Cube"] = 6;
	st["Octahedron"] = 8;
	st["Dodecahedron"] = 12;
	st["Icosahedron"] = 20;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		res += st[s];
	}
	cout << res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

