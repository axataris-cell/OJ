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
	string s; cin >> s;
	char bf = 0;
	for (int i = 0; i < s.size(); i++) {
		char u = s[i];
		if (u == '-') {
			if (bf == '-') {
				cout << 2;
				bf = 0;
			} else if (bf == 0) {
				bf = u;
			}
		} else {
			if (bf == 0) {
				cout << 0;
			} else if (bf == '-') {
				cout << 1;
				bf= 0;
			}
		}
	}
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

