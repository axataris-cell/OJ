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
	string s; cin >> s;
	int n = s.size();
	if (n <= 2) {
		cout << "NO" << el;
		return;
	}
	if (s[0] == '1' && s[1] == '0') {
		if (stoi(s.substr(2, n - 2)) < 2) {
			cout <<"NO" << el;
			return;
		}
		if (to_string(stoi(s.substr(2, n - 2))) == s.substr(2, n - 2)) {
			cout << "YES" << el;
		} else cout << "NO" << el;
	} else cout << "NO" << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


