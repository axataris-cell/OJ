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
	string s; cin >> s;
	if (s.length() != 5) {
		cout << "NO" << el;
		return;
	}
	map<char, int> mp;
	for (auto c : s) ++mp[c];
	const string T = "Timur";
	map<char, int> mp2;
	for (auto c : T) ++mp2[c];
	cout << (mp == mp2 ? "YES" : "NO") << el; 
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

