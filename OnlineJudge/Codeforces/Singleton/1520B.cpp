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
vector<int> lwb;
void testcase() {
	int n; cin >> n;
	cout << upper_bound(lwb.begin() + 1, lwb.end(), n) - lwb.begin() - 1 << el;
}
int32_t main() {
    fastio file();
    lwb.push_back(0);
    for (int len = 1; len <= 9; len++) {
    	for (int i = 1; i <= 9; i++) {
    		string s = "";
    		for (int j = 1; j <= len; j++) s += to_string(i);
    		lwb.push_back(stoi(s));
		}
	}
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


