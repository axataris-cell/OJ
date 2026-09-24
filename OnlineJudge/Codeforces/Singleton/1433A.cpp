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
vector<string> bruh;
void testcase() {
	string n; cin >> n;
	int res = 0;
	for (auto s : bruh) {
		res += s.size();
		if (s == n)break;
	}
	cout << res << el;
}
int32_t main() {
    fastio file();
    for (int i = 0; i < 9; i++) {
    	string s = "";
    	for (int j = 1; j <= 4; j++) {
    		s += char(i + '1');
    		bruh.push_back(s);
		}
	}
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

