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
	string s, t; cin >> s >> t;
	vector<int> mp(26, 0);
	for (int i = 'a'; i <= 'z'; i++) {
		mp[i - 'a'] = i - 'a';
	}
	
	int rev = 0;
	for (auto dir : t) {
		vector<int> nmap(26, 0);
		vector<int> mask(26, 0);
		for (int i = 0; i < 26; i++) mask[i] = i;
		if (dir == 'h') {
			rev ^= 1;
			mask['b' - 'a'] = 'd' - 'a';
			mask['p' - 'a'] = 'q' - 'a';
			mask['q' - 'a'] = 'p' - 'a';
			mask['d' - 'a'] = 'b' - 'a'; 
		} else if (dir == 'v') {
			mask['b' - 'a'] = 'p' - 'a';
			mask['p' - 'a'] = 'b' - 'a';
			mask['d' - 'a'] = 'q' - 'a';
			mask['q' - 'a'] = 'd' - 'a';
		} else {
			rev ^= 1;
			mask['b' - 'a'] = 'q' - 'a';
			mask['q' - 'a'] = 'b' - 'a';
			mask['p' - 'a'] = 'd' - 'a';
			mask['d' - 'a'] = 'p' - 'a';
		}
		for (int i = 0; i < 26; i++) {
			nmap[i] = mask[mp[i]];
		}
		mp = nmap;
	}
	
	for (auto &c : s) {
		c = mp[c - 'a'] + 'a';
	}
	
	if (rev) reverse(s.begin(), s.end());
	
	cout << s;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}


